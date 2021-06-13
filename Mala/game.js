let W = 500
let H = 450

let IW = 100 // Input Width

let DEBUG = true

class Line {
    constructor(x1, y1, x2, y2, ladder) {
        this.x1 = x1
        this.y1 = y1
        this.x2 = x2
        this.y2 = y2
        this.ladder = ladder
    }

    render() {
        push()
        stroke((this.ladder ? 'green' : 'red'))
        line(this.x1, this.y1, this.x2, this.y2)
        pop()
    }
}

class Cell {
    constructor(x, y, w, i, table) {
        this.x = x
        this.y = y
        this.w = w
        this.i = i
        this.table = table
        this.tele = null
        this.clicked = false
        this.next = null
        this.prev = null
    }

    mouseIsInside = () => {
        return (
            mouseX > this.x - this.w / 2
            &&
            mouseX < this.x + this.w / 2
            &&
            mouseY > this.y - this.w / 2
            &&
            mouseY < this.y + this.w / 2
        )
    }

    mouseIn = () => {
        fill(200)
        
        if (mouseIsPressed) {
            this.mousePressed()
        } else {
            this.clicked = false
        }
    }

    mousePressed = () => {
        if (!this.clicked) {
            console.log("Cell " + this.i + " clicked!")
            this.table.click(this)
            this.clicked = true
        }
    }

    mouseOut = () => {
        fill(255)
    }

    render = () => {
        push()
        if (this.mouseIsInside()) {
            this.mouseIn()
        } else {
            this.mouseOut()
        }
        rect(this.x, this.y, this.w)
        fill(0)
        text(this.i, this.x - this.w / 2 + 1, this.y + this.w / 2 - 1)
        pop()
    }
}

class Table {
    constructor(x, y, w, n) {
        this.x = x
        this.y = y
        this.w = w
        this.n = n
        
        this.head = null
        this.tail = null

        this.snakes_and_ladders = []

        this.source = null
        this.target = null

        this.cell_width = w / n

        this.initCells()
    }

    click = (cell) => {
        if (cell.tele != null) return
        
        if (this.source == null) {
            this.source = cell
        } else if (this.target == null) {
            this.target = cell
            this.connect()
            this.source = null
            this.target = null
        }
    }

    connect = () => {
        let { source, target } = this

        this.snakes_and_ladders.push(new Line(source.x, source.y, target.x, target.y, (source.i < target.i)))
        source.tele = target
    }

    mouseIsInside = (i, j) => {
        let k = i * this.n + j + 1

        let trav = this.head
        while (trav != null) {
            k--
            if (k == 0) return trav.mouseIsInside()
            trav = trav.next
        }
    }

    initCells = () => {
        let i = 0
        let j = 0
        let k = 0
        let d = 1

        while (i < this.n) {
            while (j >= 0 && j < this.n) {
                let cell = new Cell(
                        (j + .5) * this.cell_width + 10,
                        10 + (this.n - 0.5 - i) * this.cell_width,
                        this.cell_width,
                        ++k,
                        this
                )

                if (j == 0 && i == 0) {
                    this.head = cell;
                    this.tail = this.head
                } else {
                    cell.prev = this.tail
                    this.tail.next = cell
                    this.tail = cell
                }
                j += d
            }
            j -= d
            d *= -1
            i++
        }
    }

    renderCells = () => {
        let trav = this.head

        while (trav != null) {
            trav.render()
            trav = trav.next
        }
    }

    render = () => {
        rect(this.x, this.y, this.w)
        this.renderCells()
        this.snakes_and_ladders.forEach(line => line.render())
    }
}

class Player {
    constructor() {
        this.name = null
        // Marble
    }
}

class LadderSnake {
    constructor() {
        this.p1 = new Player()
        this.p2 = new Player()
        this.logged_in = false

        this.table = new Table(185, 185, 350, 10)
        
        this.init()
        if (DEBUG) this.debug()
    }

    debug = () => {
        this.logged_in = true
        this.disposeInputs()
    }

    submit = () => {
        this.p1.name = this.p1_input.value()
        this.p2.name = this.p2_input.value()

        this.disposeInputs()
        this.logged_in = true
    }

    init = () => {
        this.p1_input = createInput()
        this.p1_input.size(IW)
        this.p1_input.position(W / 2 - IW / 2, 150)

        this.p2_input = createInput()
        this.p2_input.size(IW)
        this.p2_input.position(W / 2 - IW / 2, 180)

        this.submit_button = createButton('Enter')
        this.submit_button.size(IW + 9)
        this.submit_button.position(W / 2 - IW / 2, 210)
        this.submit_button.mousePressed(this.submit)
    }

    showLoginInput = () => {
        push()
        fill(100, 220, 220, 0.6 * 225)
        rect(W / 2, H / 2, W, H)
        pop()
    }

    disposeInputs = () => {
        this.p1_input.remove()
        this.p2_input.remove()
        this.submit_button.remove()
    }

    render = () => {
        this.table.render()
        if (! this.logged_in) {
            this.showLoginInput()
        }
    }
}

let game

function setup() {
    createCanvas(W, H)
    rectMode(CENTER)
    game = new LadderSnake()
}

function draw() {
    background(220)
    game.render()
}