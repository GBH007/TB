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
)

func randomName() string {
	val := "qwertyuiopasdfghjklzxcvbnm0123456789"
	buff := new(bytes.Buffer)
	for i := 0; i < 5; i++ {
		buff.WriteByte(val[rand.Intn(len(val))])
	}
	return buff.String()
}

type Item struct {
	Type     string `json:"type"`
	Name     string `json:"name"`
	MainStat int    `json:"main"`
	AddStat  int    `json:"add"`
	Price    int    `json:"price"`
}
type Tank struct {
	Gun     *Item  `json:"gun"`
	Carcase *Item  `json:"carcase"`
	Name    string `json:"name"`
}
type User struct {
	Name  string  `json:"name"`
	Money int     `json:"money"`
	Wins  int     `json:"wins"`
	Loses int     `json:"loses"`
	Items []*Item `json:"items"`
	Tanks []*Tank `json:"tanks"`
}
type Data struct {
	User  User    `json:"user"`
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
	c.load(c.filename)
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
func (c *Controller) generateData() {
	c.data = new(Data)
	c.data.User.Name = "NoName"
	c.data.User.Money = 1000
	c.data.User.Items = make([]*Item, 0)
	c.data.User.Tanks = make([]*Tank, 0)
	for i := 0; i < 100; i++ {
		item := new(Item)
		item.Name = randomName()
		item.MainStat = rand.Intn(100)
		item.AddStat = rand.Intn(100)
		item.Price = rand.Intn(1000)
		if rand.Float64() < 0.5 {
			item.Type = GUN
		} else {
			item.Type = CARCASE
		}
		c.data.Items = append(c.data.Items, item)
	}
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
func (g *GUI) getMenuAnsven(v []string, title string, info []string) int {
	ok := false
	for !ok {
		fmt.Println(strings.Repeat("*", len(title)+2))
		fmt.Printf("*%s*\n", title)
		fmt.Println(strings.Repeat("*", len(title)+2))
		for _, s := range info {
			fmt.Printf("(%s)\n", s)
		}
		for i, s := range v {
			fmt.Printf("%d->%s\n", i, s)
		}
		if slc, err := strconv.Atoi(g.text()); err == nil {
			ok = true
			return slc
		}
	}
	return -1
}

func main() {
	c := NewConroller("db.json")
	c.generateData()
	c.Save()
	g := NewGUI(c)
	g.getMenuAnsven([]string{"sel1", "sel2"}, "TB GO", []string{"info1"})
}
