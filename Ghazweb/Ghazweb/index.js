const express = require('express')
const cors = require('cors') // middleware

// Create the app
const app = express()

// Middleware
app.use(express.json())
app.use(cors())


// Post request handlers
// url = 'api/sum'
// fun = function (req, res) {
//     let n = req.body.n
//     let m = req.body.m
//     let ans = n + m
//     res.send(`${ans}`)
// }
// app.post(url, fun);

app.post('/api/sum', function (req, res) {
    let {n, m} = req.body
    let ans = n + m
    res.send(`${ans}`)
})

app.post('/api/dif', function (req, res) {
    let {n, m} = req.body
    let ans = n - m
    res.send(`${ans}`)
})

app.post('/api/mul', function (req, res) {
    let {n, m} = req.body
    let ans = n * m
    res.send(`${ans}`)
})

app.post('/api/div', function (req, res) {
    let {n, m} = req.body
    let ans = n / m
    res.send(`${ans}`)
})


// Run
app.listen(8080, () => {
  console.log(`Server is up on port 8080`)
})