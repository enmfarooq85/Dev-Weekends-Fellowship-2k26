const express = require("express");
const mongoose = require("mongoose");
const cors = require("cors");

const app = express();
app.use(express.json());

app.use(cors({ origin: "http://localhost:3000" }));

// Mongo connection (IMPORTANT: use service name "mongo")
mongoose.connect("YOUR MONGODB URL");

const User = mongoose.model("User", { name: String });

// API route
app.get("/", (req, res) => {
  res.send("Backend is running inside Docker");
});

app.post("/user", async (req, res) => {
  const user = new User(req.body);
  await user.save();
  res.send(user);
});

app.listen(5000, () => {
  console.log("Backend running on port 5000");
});
