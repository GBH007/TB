package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type GUI struct {
	scanner    *bufio.Scanner
	controller *Controller
}

func NewGUI(cnt *Controller) *GUI {
	g := new(GUI)
	g.scanner = bufio.NewScanner(os.Stdin)
	g.controller = cnt
	return g
}
func (g *GUI) text() string {
	g.scanner.Scan()
	return g.scanner.Text()
}
func (g *GUI) printHead(title string) {
	fmt.Println(strings.Repeat("*", len(title)+2))
	fmt.Printf("*%s*\n", title)
	fmt.Println(strings.Repeat("*", len(title)+2))
}
func (g *GUI) printList(list []string, numerated bool) {
	for i, s := range list {
		if numerated {
			fmt.Printf("%d -> %s\n", i, s)
		} else {
			fmt.Printf("( %s )\n", s)
		}
	}
}
func (g *GUI) printTable(table [][]string) {
	lens := make([]int, len(table[0]))
	for _, row := range table {
		for i, cell := range row {
			lens[i] = max(lens[i], len(cell))
		}
	}
	for _, row := range table {
		fmt.Print("|")
		for i, cell := range row {
			fmt.Printf(" %"+strconv.Itoa(lens[i])+"s |", cell)
		}
		fmt.Print("\n")
	}
}
func (g *GUI) printTableWithHead(table [][]string, head []string) {
	newTable := append([][]string{head}, table...)
	g.printTable(newTable)
}
func (g *GUI) printTableWithIndexAndHead(table [][]string, head []string) {
	newTable := make([][]string, len(table))
	newHead := append([]string{"index"}, head...)
	for i, row := range table {
		newTable[i] = append([]string{strconv.Itoa(i)}, row...)
	}
	newTable = append([][]string{newHead}, newTable...)
	g.printTable(newTable)
}
func (g *GUI) getMenuAnswer(v []string, title string, info []string) int {
	for true {
		g.printHead(title)
		g.printList(info, false)
		g.printList(v, true)
		if slc, err := strconv.Atoi(g.text()); err == nil && slc > -1 && slc < len(v) {
			return slc
		}
	}
	return -1
}
func (g *GUI) getTableAnswer(table [][]string, head []string, title string, info []string, printer func([][]string, []string)) int {
	for true {
		g.printHead(title)
		g.printList(info, false)
		printer(table, head)
		fmt.Println("enter index\npress enter to cancel")
		ans := g.text()
		if ans == "" {
			return -1
		}
		if slc, err := strconv.Atoi(ans); err == nil {
			return slc
		}
	}
	return -1
}
func (g *GUI) convertItemsToTableAndHead(items map[int]*Item) ([][]string, []string) {
	head := []string{"index", "name", "type", "main stat", "price"}
	table := make([][]string, 0)
	for i, item := range items {
		table = append(table, []string{
			strconv.Itoa(i),
			item.Name,
			item.Type,
			strconv.Itoa(item.MainStat),
			strconv.Itoa(item.Price),
		})
	}
	return table, head
}
func (g *GUI) convertTanksToTableAndHead(tanks map[int]*Tank) ([][]string, []string) {
	head := []string{"index", "name", "gun stat", "carcase stat", "price"}
	table := make([][]string, 0)
	for i, tank := range tanks {
		table = append(table, []string{
			strconv.Itoa(i),
			tank.Name,
			strconv.Itoa(tank.Gun.MainStat),
			strconv.Itoa(tank.Carcase.MainStat),
			strconv.Itoa(tank.Gun.Price + tank.Carcase.Price)})
	}
	return table, head
}
func (g *GUI) Run() {
	for true {
		ans := g.getMenuAnswer(
			[]string{"exit", "armory", "shop", "battle", "admin"}, "TANK BATTLE", []string{"with GO", VERSION})
		switch ans {
		case 0:
			return
		case 1:
			g.armoryMenu()
		case 2:
			g.shopMenu()
		case 3:
			g.battleMenu()
		case 4:
			g.adminMenu()
		}
	}
}
func (g *GUI) adminMenu() {
	for true {
		ans := g.getMenuAnswer(
			[]string{"exit", "generate data", "save", "load"}, "ADMIN", []string{"filename", g.controller.filename})
		switch ans {
		case 0:
			return
		case 1:
			g.controller.generateData()
		case 2:
			g.controller.Save()
		case 3:
			g.controller.Load()
		}
	}
}
func (g *GUI) battleMenu() {
	for true {
		tanks := g.controller.GetUserTanks()
		table, head := g.convertTanksToTableAndHead(tanks)
		index := g.getTableAnswer(table, head, "SELECT TANK", []string{}, g.printTableWithHead)
		if _, ok := tanks[index]; !ok || index == -1 {
			return
		}
		tank := tanks[index]
		hp := tank.Carcase.MainStat
		pw := tank.Gun.MainStat
		enemys := [][]int{
			{hp - 10, pw - 10, (hp - 10) * 60 / hp},
			{hp, pw, 60},
			{hp + 10, pw + 10, (hp + 10) * 60 / hp},
			{100, 100, 100 * 60 / hp},
		}
		names := []string{"easy", "normal", "hard", "ADMIN"}
		table = make([][]string, len(enemys))
		for i, row := range enemys {
			table[i] = []string{
				names[i],
				strconv.Itoa(row[0]),
				strconv.Itoa(row[1]),
				strconv.Itoa(row[2]),
			}
		}
		head = []string{"level", "carcase HP", "gun power", "reward"}
		index = g.getTableAnswer(table, head, "SELECT ENEMY", []string{}, g.printTableWithIndexAndHead)
		if index == -1 {
			return
		}
		enemy := &Tank{
			Name:    names[index],
			Gun:     &Item{MainStat: enemys[index][1]},
			Carcase: &Item{MainStat: enemys[index][0]},
		}
		g.printBattle(tank, enemy, enemys[index][2])
	}
}
func (g *GUI) printBattle(player, enemy *Tank, reward int) {
	g.printHead("BATTLE!")
	bl := g.controller.Battle(player, enemy, reward)
	for _, step := range bl.Steps {
		fmt.Println(strings.Repeat("-", 30))
		fmt.Printf("%s loses %d HP\n", step.TargetName, step.Damage)
		if step.RandomCoeff == 2 {
			fmt.Println("VOT ETO KRIT!!!!!!!!")
		}
	}
	if bl.Win {
		fmt.Println("You WIN!!!")
	} else {
		fmt.Println("You LOSE!!!")
	}
}
func (g *GUI) printResult(res bool) {
	if res == true {
		fmt.Println("SUCCESS")
	} else {
		fmt.Println("FAILED")
	}
}
func (g *GUI) armoryMenu() {
	for true {
		ans := g.getMenuAnswer(
			[]string{"exit", "my gun", "my carcase", "my tank"}, "ARMORY",
			[]string{
				"wins " + strconv.Itoa(g.controller.GetUser().Wins),
				"loses " + strconv.Itoa(g.controller.GetUser().Loses)})
		switch ans {
		case 0:
			return
		case 1:
			items := g.controller.GetUserItemByType(GUN)
			table, head := g.convertItemsToTableAndHead(items)
			g.printTableWithHead(table, head)
		case 2:
			items := g.controller.GetUserItemByType(CARCASE)
			table, head := g.convertItemsToTableAndHead(items)
			g.printTableWithHead(table, head)
		case 3:
			g.tankEditMenu()
		}
	}
}
func (g *GUI) tankEditMenu() {
	for true {
		ans := g.getMenuAnswer(
			[]string{"exit", "view my tanks", "assemble new tank", "disassemble my tank"}, "MY TANKS",
			[]string{})
		switch ans {
		case 0:
			return
		case 1:
			tanks := g.controller.GetUserTanks()
			table, head := g.convertTanksToTableAndHead(tanks)
			g.printTableWithHead(table, head)
		case 2:
			guns := g.controller.GetUserItemByType(GUN)
			table, head := g.convertItemsToTableAndHead(guns)
			gunIndex := g.getTableAnswer(table, head, "SELECT GUN", []string{}, g.printTableWithHead)
			if gunIndex == -1 {
				continue
			}
			carcase := g.controller.GetUserItemByType(CARCASE)
			table, head = g.convertItemsToTableAndHead(carcase)
			carcaseIndex := g.getTableAnswer(table, head, "SELECT CARCASE", []string{}, g.printTableWithHead)
			if carcaseIndex == -1 {
				continue
			}
			fmt.Println("enter tank name or press enter to cancel")
			name := g.text()
			if name == "" {
				continue
			}
			g.printResult(g.controller.AssembleTank(gunIndex, carcaseIndex, name))
		case 3:
			tanks := g.controller.GetUserTanks()
			table, head := g.convertTanksToTableAndHead(tanks)
			index := g.getTableAnswer(table, head, "SELECT TANK", []string{}, g.printTableWithHead)
			if index != -1 {
				g.printResult(g.controller.DisassembleTank(index))
			}
		}
	}
}
func (g *GUI) shopMenu() {
	for true {
		ans := g.getMenuAnswer([]string{"exit", "buy gun", "buy carcase", "sale item"}, "SHOP", []string{"your money", strconv.Itoa(g.controller.GetUser().Money)})
		switch ans {
		case 0:
			return
		case 1:
			guns := g.controller.GetItemByType(GUN)
			table, head := g.convertItemsToTableAndHead(guns)
			index := g.getTableAnswer(table, head, "BUY GUN", []string{"your money", strconv.Itoa(g.controller.GetUser().Money)}, g.printTableWithHead)
			if index != -1 {
				g.printResult(g.controller.BuyItem(guns[index]))
			}
		case 2:
			carcase := g.controller.GetItemByType(CARCASE)
			table, head := g.convertItemsToTableAndHead(carcase)
			index := g.getTableAnswer(table, head, "BUY CARCASE", []string{"your money", strconv.Itoa(g.controller.GetUser().Money)}, g.printTableWithHead)
			if index != -1 {
				g.printResult(g.controller.BuyItem(carcase[index]))
			}
		case 3:
			items := g.controller.GetUser().Items
			table, head := g.convertItemsToTableAndHead(items)
			index := g.getTableAnswer(table, head, "SALE ITEM", []string{"your money", strconv.Itoa(g.controller.GetUser().Money)}, g.printTableWithHead)
			if index != -1 {
				g.printResult(g.controller.SaleItem(index))
			}
		}
	}
}
