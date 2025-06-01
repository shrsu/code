import React, { useContext, useState, useEffect } from "react";
import "./Result.css";
import { Theme } from "../App";

function Result(props) {
  // importing the theme form App using use context
  let theme = useContext(Theme);

  // css property to set the visibility of the result div
  const resultCss = {
    display: props.visibility == "none" ? "none" : "flex",
  };

  const [textColor, setTextColor] = useState("blue");

  // updating the color according to the theme using useState
  useEffect(() => {
    setTextColor(theme === "light" ? "blue" : "white");
  }, [theme]);

// state to maintain feedback 
  const [feedback, setFeedback] = useState("");

  useEffect(() => {
    setFeedback(
      props.score > 2
        ? props.score === 5
          ? "100%!!! You nailed it!"
   