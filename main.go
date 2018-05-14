package main

import (
	"bufio"
	"bytes"
	"encoding/json"
	"fmt"
	"log"
	"math/rand"
	"os"
	"strconv"
	"strings"
)

const (
	GUN     = "gun"
	CARCASE = "carcase"
	VERSION = "v0.0"
)

func selectItemByType(items []*Item, t string) []*Item {
	res := make([]*Item, 0)
	for _, item := range items {
		if item.Type == t {
			res = append(res, item)
		}
	}
	return res
}
func randomName() string {
	val := "qwertyuiopasdfghjklzxcvbnm0123456789"
	buff := new(bytes.Buffer)
	for i := 0; i < 5; i++ {
		buff.WriteByte(val[rand.Intn(len(val))])
	}
	return buff.String()
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

type Item struct {
	Type     string `json:"type"`
	Name     string `json:"name"`
	MainStat int    `json:"main"`
	Price    int    `json:"price"`
}
type Tank struct {
	Gun     *Item  `json:"gun"`
	Carcase *Item  `json:"carcase"`
	Name    string `json:"name"`
}
type User struct {
	Money int     `json:"money"`
	Wins  int     `json:"wins"`
	Loses int     `json:"loses"`
	Items []*Item `json:"items"`
	Tanks []*Tank `json:"tanks"`
}
type Data struct {
	User  *User   `json:"user"`
	Items []*Item `json:"items"`
}
type Controller struct {
	data     *Data
	filename string
}

func NewConroller(filename string) *Controller {
	c := new(Controller)
	c.load(filename)
	c.filename = filename
	return c
}
func (c *Controller) Load() {
	if err := c.load(c.filename); err != nil {
		log.Println(err)
		//c.makeData()
	}
}
func (c *Controller) load(filename string) error {
	c.makeData()
	file, err := os.Open(filename)
	if err != nil {
		log.Println(err)
		return err
	}
	decoder := json.NewDecoder(file)
	return decoder.Decode(c.data)
}
func (c *Controller) Save() {
	c.save(c.filename)
}
func (c *Controller) save(filename string) error {
	file, err := os.Create(filename)
	if err != nil {
		log.Println(err)
		return err
	}
	encoder := json.NewEncoder(file)
	return encoder.Encode(c.data)
}
func (c *Controller) makeData() {
	c.data = new(Data)
	c.data.User = new(User)
	c.data.User.Money = 1000
	c.data.User.Items = make([]*Item, 0)
	c.data.User.Tanks = make([]*Tank, 0)
	c.data.Items = make([]*Item, 0)
}
func (c *Controller) generateData() {
	c.makeData()
	for i := 0; i < 10; i++ {
		item := new(Item)
		item.Name = randomName()
		item.MainStat = rand.Intn(100)
		item.Price = rand.Intn(1000)
		if rand.Float64() < 0.5 {
			item.Type = GUN
		} else {
			item.Type = CARCASE
		}
		c.data.Items = append(c.data.Items, item)
	}
}
func (c *Controller) GetItemByType(t string) []*Item {
	return selectItemByType(c.data.Items, t)
}
func (c *Controller) GetUserItemByType(t string) []*Item {
	return selectItemByType(c.data.User.Items, t)
}
func (c *Controller) GetUser() *User {
	return c.data.User
}
func (c *Controller) BuyItem(item *Item) bool {
	if c.data.User.Money < item.Price {
		return false
	}
	c.data.User.Items = append(c.data.User.Items, item)
	c.data.User.Money -= item.Price
	return true
}
func (c *Controller) SaleItem(index int) bool {
	item := c.data.User.Items[index]
	c.data.User.Items = append(c.data.User.Items[:index], c.data.User.Items[index+1:]...)
	c.data.User.Money += item.Price
	return true
}
func (c *Controller) GetUserTanks() []*Tank {
	return c.data.User.Tanks
}
func (c *Controller) AssembleTank(gunIndex, carcaseIndex int, name string) bool {
	gun := c.data.User.Items[gunIndex]
	carcase := c.data.User.Items[carcaseIndex]
	items := make([]*Item, 0)
	for i, item := range c.data.User.Items {
		if i != gunIndex && i != carcaseIndex {
			items = append(items, item)
		}
	}
	tank := &Tank{Name: name, Gun: gun, Carcase: carcase}
	c.data.User.Tanks = append(c.data.User.Tanks, tank)
	return true
}
func (c *Controller) DisassembleTank(index int) bool {
	tank := c.data.User.Tanks[index]
	c.data.User.Items = append(c.data.User.Items, tank.Gun, tank.Carcase)
	c.data.User.Tanks = append(c.data.User.Tanks[:index], c.data.User.Tanks[index+1:]...)
	return true
}

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
func (g *GUI) getTableAnswer(table [][]string, head []string, title string, info []string) int {
	for true {
		g.printHead(title)
		g.printList(info, false)
		g.printTableWithIndexAndHead(table, head)
		fmt.Println("enter index from 0 to", len(table)-1, "\npress enter to cancel")
		ans := g.text()
		if ans == "" {
			return -1
		}
		if slc, err := strconv.Atoi(ans); err == nil && slc > -1 && slc < len(table) {
			return slc
		}
	}
	return -1
}
func (g *GUI) convertItemsToTableAndHead(items []*Item) ([][]string, []string) {
	head := []string{"name", "type", "main stat", "price"}
	return g.convertItemsToTable(items), head
}
func (g *GUI) convertItemsToTable(items []*Item) [][]string {
	table := make([][]string, len(items))
	for i, item := range items {
		table[i] = []string{item.Name, item.Type, strconv.Itoa(item.MainStat), strconv.Itoa(item.Price)}
	}
	return table
}
func (g *GUI) convertTanksToTableAndHead(tanks []*Tank) ([][]string, []string) {
	head := []string{"name", "gun stat", "carcase stat", "price"}
	table := make([][]string, len(tanks))
	for i, tank := range tanks {
		table[i] = []string{
			tank.Name,
			strconv.Itoa(tank.Gun.MainStat),
			strconv.Itoa(tank.Carcase.MainStat),
			strconv.Itoa(tank.Gun.Price + tank.Carcase.Price)}
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
		}
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
			items := selectItemByType(g.controller.GetUser().Items, GUN)
			table, head := g.convertItemsToTableAndHead(items)
			g.printTableWithIndexAndHead(table, head)
		case 2:
			items := selectItemByType(g.controller.GetUser().Items, CARCASE)
			table, head := g.convertItemsToTableAndHead(items)
			g.printTableWithIndexAndHead(table, head)
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
			g.printTableWithIndexAndHead(table, head)
		case 2:
			guns := g.controller.GetUserItemByType(GUN)
			table, head := g.convertItemsToTableAndHead(guns)
			gunIndex := g.getTableAnswer(table, head, "SELECT GUN", []string{})
			if gunIndex == -1 {
				continue
			}
			carcase := g.controller.GetUserItemByType(CARCASE)
			table, head = g.convertItemsToTableAndHead(carcase)
			carcaseIndex := g.getTableAnswer(table, head, "SELECT CARCASE", []string{})
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
			index := g.getTableAnswer(table, head, "SELECT TANK", []string{})
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
			index := g.getTableAnswer(table, head, "BUY GUN", []string{"your money", strconv.Itoa(g.controller.GetUser().Money)})
			if index != -1 {
				g.printResult(g.controller.BuyItem(guns[index]))
			}
		case 2:
			carcase := g.controller.GetItemByType(CARCASE)
			table, head := g.convertItemsToTableAndHead(carcase)
			index := g.getTableAnswer(table, head, "BUY CARCASE", []string{"your money", strconv.Itoa(g.controller.GetUser().Money)})
			if index != -1 {
				g.printResult(g.controller.BuyItem(carcase[index]))
			}
		case 3:
			items := g.controller.GetUser().Items
			table, head := g.convertItemsToTableAndHead(items)
			index := g.getTableAnswer(table, head, "SALE ITEM", []string{"your money", strconv.Itoa(g.controller.GetUser().Money)})
			if index != -1 {
				g.printResult(g.controller.SaleItem(index))
			}
		}
	}
}

func main() {
	c := NewConroller("db.json")
	//c.generateData()
	//c.Save()
	c.Load()
	g := NewGUI(c)
	g.Run()
}
