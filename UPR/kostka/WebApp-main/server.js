const express = require('express')
const path = require('path')
const { report } = require('process')

const app = express()
const http = require('http').createServer(app)

app.use(express.static(path.join(__dirname, 'public')))

const io = require('socket.io')(http)
io.on('connection', socket=>{
    console.log('connected ready')
    
    socket.on('sendMessage', msg =>{
        socket.broadcast.emit('sendToAll', msg)
    })
})

const PORT = process.env.PORT || 3000
http.listen(PORT, () =>{
    console.log('Server běží na portu', PORT)
})