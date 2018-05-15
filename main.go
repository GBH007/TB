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

func selectItemByType(items map[int]*Item, t string) map[int]*Item {
	res := make(map[int]*Item)
	for i, item := range items {
		if item.Type == t {
			res[i] = item
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
	Money      int           `json:"money"`
	Wins       int           `json:"wins"`
	Loses      int           `json:"loses"`
	Items      map[int]*Item `json:"items"`
	Tanks      map[int]*Tank `json:"tanks"`
	LastItemId int           `json:"last_item_id"`
	LastTankId int           `json:"last_tank_id"`
}

func (u *User) AddItem(item *Item) {
	u.Items[u.LastItemId] = item
	u.LastItemId++
}
func (u *User) DelItem(index int) {
	delete(u.Items, index)
}
func (u *User) AddTank(tank *Tank) {
	u.Tanks[u.LastTankId] = tank
	u.LastTankId++
}
func (u *User) DelTank(index int) {
	delete(u.Tanks, index)
}

type Data struct {
	User       *User         `json:"user"`
	Items      map[int]*Item `json:"items"`
	LastItemId int           `json:"last_item_id"`
}

func (d *Data) AddItem(item *Item) {
	d.Items[d.LastItemId] = item
	d.LastItemId++
}
func (d *Data) DelItem(index int) {
	delete(d.Items, index)
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
	c.data.User.Items = make(map[int]*Item)
	c.data.User.Tanks = make(map[int]*Tank)
	c.data.Items = make(map[int]*Item)
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
		c.data.AddItem(item)
	}
}
func (c *Controller) GetItemByType(t string) map[int]*Item {
	return selectItemByType(c.data.Items, t)
}
func (c *Controller) GetUserItemByType(t string) map[int]*Item {
	return selectItemByType(c.data.User.Items, t)
}
func (c *Controller) GetUser() *User {
	return c.data.User
}
func (c *Controller) BuyItem(item *Item) bool {
	if c.data.User.Money < item.Price {
		return false
	}
	c.data.User.AddItem(item)
	c.data.User.Money -= item.Price
	return true
}
func (c *Controller) SaleItem(index int) bool {
	item, ok := c.data.User.Items[index]
	if !ok {
		return false
	}
	c.data.User.DelItem(index)
	c.data.User.Money += item.Price
	return true
}
func (c *Controller) GetUserTanks() map[int]*Tank {
	return c.data.User.Tanks
}
func (c *Controller) AssembleTank(gunIndex, carcaseIndex int, name string) bool {
	gun, ok := c.data.User.Items[gunIndex]
	if !ok {
		return false
	}
	carcase, ok := c.data.User.Items[carcaseIndex]
	if !ok {
		return false
	}
	c.data.User.DelItem(gunIndex)
	c.data.User.DelItem(carcaseIndex)
	tank := &Tank{Name: name, Gun: gun, Carcase: carcase}
	c.data.User.AddTank(tank)
	return true
}
func (c *Controller) DisassembleTank(index int) bool {
	tank, ok := c.data.User.Tanks[index]
	if !ok {
		return false
	}
	c.data.User.AddItem(tank.Gun)
	c.data.User.AddItem(tank.Carcase)
	c.data.User.DelTank(index)
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
func (g *GUI) printTableWithHead(table [][]string, head []string) {
	newTable := append([][]string{head}, table...)
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
		g.printTableWithHead(table, head)
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
	return g.convertItemsToTable(items), head
}
func (g *GUI) convertItemsToTable(items map[int]*Item) [][]string {
	table := make([][]string, 0)
	for i, item := range items {
		table = append(table, []string{strconv.Itoa(i), item.Name, item.Type, strconv.Itoa(item.MainStat), strconv.Itoa(item.Price)})
	}
	return table
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
