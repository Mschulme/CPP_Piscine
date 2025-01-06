/****************************
 *       CONFIG SECTION     *
 ****************************/
const canvas = document.getElementById("myCanvasMarc");
const ctx = canvas.getContext("2d");

// Canvas Dimensions
// (You may want to ensure your <canvas> has a specific width/height in HTML)
const CANVAS_WIDTH = canvas.width;
const CANVAS_HEIGHT = canvas.height;

// Ball
const BALL_RADIUS = 10;
const INITIAL_BALL_SPEED_X = 2; 
const INITIAL_BALL_SPEED_Y = 1.5; 

// Paddles
const PADDLE_WIDTH = 10;
const PADDLE_HEIGHT = 75;
const PADDLE_MOVE_SPEED = 5; 

// Game State
let x = CANVAS_WIDTH / 2;
let y = CANVAS_HEIGHT / 2;
let dx = INITIAL_BALL_SPEED_X;
let dy = INITIAL_BALL_SPEED_Y;

// Left Paddle
let paddleLeftY = (CANVAS_HEIGHT - PADDLE_HEIGHT) / 2;
let wPressed = false;
let sPressed = false;

// Right Paddle
let paddleRightY = (CANVAS_HEIGHT - PADDLE_HEIGHT) / 2;
let upPressed = false;
let downPressed = false;

// Game Control
let animationId = null;
let isGameOver = false;

/****************************
 *    EVENT LISTENERS       *
 ****************************/
document.addEventListener("keydown", keyDownHandler, false);
document.addEventListener("keyup", keyUpHandler, false);

/**
 * keyDownHandler
 */
function keyDownHandler(e) {
  // Left paddle: W/S
  if (e.key === "w" || e.key === "W") {
    wPressed = true;
  } else if (e.key === "s" || e.key === "S") {
    sPressed = true;
  }

  // Right paddle: Up/Down arrows
  if (e.key === "ArrowUp") {
    upPressed = true;
  } else if (e.key === "ArrowDown") {
    downPressed = true;
  }
}

/**
 * keyUpHandler
 */
function keyUpHandler(e) {
  // Left paddle: W/S
  if (e.key === "w" || e.key === "W") {
    wPressed = false;
  } else if (e.key === "s" || e.key === "S") {
    sPressed = false;
  }

  // Right paddle: Up/Down arrows
  if (e.key === "ArrowUp") {
    upPressed = false;
  } else if (e.key === "ArrowDown") {
    downPressed = false;
  }
}

/****************************
 *    DRAWING FUNCTIONS     *
 ****************************/
function drawBall() {
  ctx.beginPath();
  ctx.arc(x, y, BALL_RADIUS, 0, Math.PI * 2);
  ctx.fillStyle = "#0095DD";
  ctx.fill();
  ctx.closePath();
}

function drawPaddleLeft() {
  ctx.beginPath();
  ctx.rect(0, paddleLeftY, PADDLE_WIDTH, PADDLE_HEIGHT);
  ctx.fillStyle = "green";
  ctx.fill();
  ctx.closePath();
}

function drawPaddleRight() {
  ctx.beginPath();
  ctx.rect(CANVAS_WIDTH - PADDLE_WIDTH, paddleRightY, PADDLE_WIDTH, PADDLE_HEIGHT);
  ctx.fillStyle = "red";
  ctx.fill();
  ctx.closePath();
}

/**
 * Draw a vertical line in the middle
 */
function drawCenterLine() {
  ctx.beginPath();
  ctx.moveTo(CANVAS_WIDTH / 2, 0);
  ctx.lineTo(CANVAS_WIDTH / 2, CANVAS_HEIGHT);
  ctx.strokeStyle = "#555"; // or any color
  ctx.lineWidth = 2;
  ctx.stroke();
  ctx.closePath();
}

/****************************
 *  GAME LOGIC FUNCTIONS    *
 ****************************/
function handlePaddleCollisions() {
  // Left paddle collision
  // If the ball hits the left wall within the paddle’s range
  if (x + dx < BALL_RADIUS + PADDLE_WIDTH) {
    if (y > paddleLeftY && y < paddleLeftY + PADDLE_HEIGHT) {
      // Add spin based on where it hit the paddle
      let hitPoint = y - (paddleLeftY + PADDLE_HEIGHT / 2);
      let normalized = hitPoint / (PADDLE_HEIGHT / 2);
      dy = normalized * 3; // Adjust for vertical "spin" or bounce
      dx = -dx; // Reverse horizontal direction
    } else {
      gameOver("Right Player");
    }
  }

  // Right paddle collision
  if (x + dx > CANVAS_WIDTH - (BALL_RADIUS + PADDLE_WIDTH)) {
    if (y > paddleRightY && y < paddleRightY + PADDLE_HEIGHT) {
      // Spin on right paddle
      let hitPoint = y - (paddleRightY + PADDLE_HEIGHT / 2);
      let normalized = hitPoint / (PADDLE_HEIGHT / 2);
      dy = normalized * 3;
      dx = -dx;
    } else {
      gameOver("Left Player");
    }
  }
}

function moveBall() {
  handlePaddleCollisions();

  // Top and bottom collision
  if (y + dy < BALL_RADIUS || y + dy > CANVAS_HEIGHT - BALL_RADIUS) {
    dy = -dy;
  }

  x += dx;
  y += dy;
}

function movePaddles() {
  // Move left paddle (W/S)
  if (wPressed) {
    paddleLeftY = Math.max(paddleLeftY - PADDLE_MOVE_SPEED, 0);
  }
  if (sPressed) {
    paddleLeftY = Math.min(
      paddleLeftY + PADDLE_MOVE_SPEED,
      CANVAS_HEIGHT - PADDLE_HEIGHT
    );
  }

  // Move right paddle (ArrowUp/ArrowDown)
  if (upPressed) {
    paddleRightY = Math.max(paddleRightY - PADDLE_MOVE_SPEED, 0);
  }
  if (downPressed) {
    paddleRightY = Math.min(
      paddleRightY + PADDLE_MOVE_SPEED,
      CANVAS_HEIGHT - PADDLE_HEIGHT
    );
  }
}

/****************************
 *    MAIN GAME LOOP        *
 ****************************/
function draw() {
  if (isGameOver) return;

  // Clear canvas
  ctx.clearRect(0, 0, CANVAS_WIDTH, CANVAS_HEIGHT);

  // Draw the center line
  drawCenterLine();

  // Draw the ball and paddles
  drawBall();
  drawPaddleLeft();
  drawPaddleRight();

  // Move objects
  movePaddles();
  moveBall();

  // requestAnimationFrame for smooth animation
  animationId = requestAnimationFrame(draw);
}

/**
 * Game over routine
 */
function gameOver(winner) {
  isGameOver = true;
  cancelAnimationFrame(animationId);
  alert(`Game Over! ${winner} wins!`);
  const runButton = document.getElementById("runButton");
  if (runButton) runButton.disabled = false;
}

/****************************
 *   START / RESTART LOGIC  *
 ****************************/
function resetGame() {
  // Reset ball position
  x = CANVAS_WIDTH / 2;
  y = CANVAS_HEIGHT / 2;
  dx = INITIAL_BALL_SPEED_X;
  dy = INITIAL_BALL_SPEED_Y;

  // Reset paddles
  paddleLeftY = (CANVAS_HEIGHT - PADDLE_HEIGHT) / 2;
  paddleRightY = (CANVAS_HEIGHT - PADDLE_HEIGHT) / 2;

  isGameOver = false;
}

function startGame() {
  resetGame();
  draw();
}

/****************************
 *   BUTTON EVENT LISTENER  *
 ****************************/
document.getElementById("runButtonMarc").addEventListener("click", function () {
  this.disabled = true;
  startGame();
});
