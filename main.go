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
		c.makeData()
	}
}
func (c *Controller) load(filename string) error {
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
	res := make([]*Item, 0)
	for _, item := range c.data.Items {
		if item.Type == t {
			res = append(res, item)
		}
	}
	return res
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
func (g *GUI) getMenuAnsven(v []string, title string, info []string) int {
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
func (g *GUI) getTableAnsven(table [][]string, head []string, title string, info []string) int {
	for true {
		g.printHead(title)
		g.printList(info, false)
		g.printTableWithIndexAndHead(table, head)
		fmt.Println("press enter to cancel")
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
func (g *GUI) Run() {
	for true {
		ans := g.getMenuAnsven(
			[]string{"exit", "armory", "shop", "battle", "admin"}, "TANK BATTLE", []string{"with GO", VERSION})
		switch ans {
		case 0:
			return
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
func (g *GUI) shopMenu() {
	for true {
		ans := g.getMenuAnsven([]string{"exit", "buy gun", "buy carcase", "sale item"}, "SHOP", []string{"your money", strconv.Itoa(g.controller.GetUser().Money)})
		switch ans {
		case 0:
			return
		case 1:
			guns := g.controller.GetItemByType(GUN)
			table, head := g.convertItemsToTableAndHead(guns)
			index := g.getTableAnsven(table, head, "BUY GUN", []string{"your money", strconv.Itoa(g.controller.GetUser().Money)})
			if index != -1 {
				g.printResult(g.controller.BuyItem(guns[index]))
			}
		case 2:
			carcase := g.controller.GetItemByType(CARCASE)
			table, head := g.convertItemsToTableAndHead(carcase)
			index := g.getTableAnsven(table, head, "BUY CARCASE", []string{"your money", strconv.Itoa(g.controller.GetUser().Money)})
			if index != -1 {
				g.printResult(g.controller.BuyItem(carcase[index]))
			}
		case 3:
			items := g.controller.GetUser().Items
			table, head := g.convertItemsToTableAndHead(items)
			index := g.getTableAnsven(table, head, "BUY CARCASE", []string{"your money", strconv.Itoa(g.controller.GetUser().Money)})
			if index != -1 {
				g.printResult(g.controller.SaleItem(index))
			}
		}
	}
}

func main() {
	c := NewConroller("db.json")
	c.generateData()
	c.Save()
	g := NewGUI(c)
	g.printTable(g.convertItemsToTable(c.GetItemByType(GUN)))
	g.printTableWithIndexAndHead(g.convertItemsToTableAndHead(c.GetItemByType(CARCASE)))
	g.Run()
}
