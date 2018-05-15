package main

import (
	"encoding/json"
	"log"
	"math/rand"
	"os"
)

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
