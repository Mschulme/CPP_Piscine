const canvas = document.getElementById("myCanvas");
const ctx = canvas.getContext("2d");


// Ball
let x = canvas.width / 2;
let y = canvas.height / 2;
let dx = 2;
let dy = 1.5;
const ballRadius = 12;

// Scores
let pl_1_score = 0;
let pl_2_score = 0;

// 2D Paddle positions
const paddleHeight = 100;
const paddleWidth = 10;
let paddleY_1 = (canvas.height - paddleHeight) / 2;
let paddleY_2 = (canvas.height - paddleHeight) / 2;

// Keyboard flags
let Wpressed = false;
let Spressed = false;
let UpPressed = false;
let DownPressed = false;

// 3D Variables
let scene, camera, renderer;
let paddleLeftMesh, paddleRightMesh;
let ballMesh;

// Listen for keys
document.addEventListener("keydown", keyDownHandler, false);
document.addEventListener("keyup", keyUpHandler, false);

function keyDownHandler(e) {
  if (e.key === "W" || e.key === "w") {
    Wpressed = true;
  } else if (e.key === "S" || e.key === "s") {
    Spressed = true;
  }

  if (e.key === "ArrowUp" || e.key === "Up") {
    UpPressed = true;
  } else if (e.key === "ArrowDown" || e.key === "Down") {
    DownPressed = true;
  }
}

function keyUpHandler(e) {
  if (e.key === "W" || e.key === "w") {
    Wpressed = false;
  } else if (e.key === "S" || e.key === "s") {
    Spressed = false;
  }

  if (e.key === "ArrowUp") {
    UpPressed = false;
  } else if (e.key === "ArrowDown") {
    DownPressed = false;
  }
}


function init3D() {
  scene = new THREE.Scene();

  // Orthographic camera matching the 2D canvas extents
  const left = 0;
  const right = canvas.width;
  const top = 0;
  const bottom = canvas.height;
  camera = new THREE.OrthographicCamera(left, right, top, bottom, -1000, 1000);
  camera.position.z = 10;


  // Create the renderer
  renderer = new THREE.WebGLRenderer({ antialias: true, alpha: true });
  renderer.setSize(canvas.width, canvas.height);
  renderer.domElement.classList.add("threejs-canvas");
  document.body.appendChild(renderer.domElement);

  // 1) Create geometry for paddles
  //    We'll use a BoxGeometry that is 'paddleWidth' wide & 'paddleHeight' tall.
  //    Because it's 3D, we also need a 'depth' (Z size). Let's pick 1 or 5, etc.
  const paddleGeometry = new THREE.BoxGeometry(paddleWidth, paddleHeight, 5);
  const materialLeft = new THREE.MeshBasicMaterial({ color: 0x00ff00 });
  const materialRight = new THREE.MeshBasicMaterial({ color: 0xff0000 });

  paddleLeftMesh = new THREE.Mesh(paddleGeometry, materialLeft);
  paddleRightMesh = new THREE.Mesh(paddleGeometry, materialRight);

  paddleLeftMesh.position.set(0, paddleY_1, 0);
  paddleRightMesh.position.set(canvas.width - paddleWidth, paddleY_2, 0);

  // 5) Add them to the scene
  scene.add(paddleLeftMesh);
  scene.add(paddleRightMesh);

  const ballGeometry = new THREE.SphereGeometry(ballRadius, 16, 16);
  const ballMaterial = new THREE.MeshBasicMaterial({ color: 0x0095DD });
  ballMesh = new THREE.Mesh(ballGeometry, ballMaterial);
  ballMesh.position.set(x, y, 0);
  scene.add(ballMesh);

  // Then call your animation loop
  animate3D();
}


/********************************************
 * 2) 3D ANIMATION LOOP
 ********************************************/
function animate3D() {
  requestAnimationFrame(animate3D);

  // Simple rotation
  if (paddleLeftMesh)
    paddleLeftMesh.rotation.y += 0.01;
  if (paddleRightMesh)
    paddleRightMesh.rotation.y -= 0.01;

  renderer.render(scene, camera);
}

/********************************************
 * 2D DRAWING (Ball, Scores, etc.)
 ********************************************/
function drawBall() {
  ctx.beginPath();
  ctx.arc(x, y, ballRadius, 0, Math.PI * 2);
  ctx.fillStyle = "#0095DD";
  ctx.fill();
  ctx.closePath();
}

function drawScores() {
  ctx.font = "40px Lato";
  ctx.fillStyle = "green";
  ctx.fillText(pl_1_score.toString(), canvas.width / 4, 50);
  ctx.fillStyle = "red";
  ctx.fillText(pl_2_score.toString(), (canvas.width * 3) / 4, 50);
}

/********************************************
 * 2D GAME LOGIC
 ********************************************/
function hitBall()
{
  if (x === ballRadius + paddleWidth && !((y < paddleY_1 + paddleHeight * 0.5) && (y > paddleY_1 - paddleHeight * 0.5)))
  {
    pl_2_score++;
    resetBall(1);
  }
  else if (x === canvas.width - ballRadius - paddleWidth && !((y < paddleY_2 + paddleHeight * 0.5) && (y > paddleY_2 - paddleHeight * 0.5)))
  {
    pl_1_score++;
    resetBall(2);
  }

  if (x === paddleWidth + ballRadius  || x === canvas.width - ballRadius - paddleWidth )
  {
    dx = -dx;
  }
  if (y + dy > canvas.height - ballRadius || y + dy < ballRadius)
  {
    dy = -dy;
  }
}


function pausecomp(millis)
{
    var date = new Date();
    var curDate = null;
    do { curDate = new Date(); }
    while(curDate-date < millis);
}

function resetBall(scoringPlayer) {

  pausecomp(1000);

  x = canvas.width / 2;

  const randomOffset = (Math.random() - 0.5) * 100;
  y = canvas.height / 2 + randomOffset;

  // If Player 1 scored, let the ball move to the RIGHT.
  // If Player 2 scored, let the ball move to the LEFT.
  // The magnitude of dx can stay the same or reset to a known speed.
  if (scoringPlayer === 1) {
    dx = Math.abs(dx);       // ensure dx is positive
  } else if (scoringPlayer === 2) {
    dx = -Math.abs(dx);      // ensure dx is negative
  }

  // dy = (dy > 0 ? 1 : -1) * (1.5 + Math.random() * 1.5);
}

function moveBall() {
  hitBall();
  x += dx;
  y += dy;
}


function draw() {
  // Clear the 2D canvas
  ctx.clearRect(0, 0, canvas.width, canvas.height);

  // Draw scores, ball
  drawScores();
  //drawBall();

  // Update paddle positions from keyboard
  if (Wpressed) {
    paddleY_1 = Math.max(paddleY_1 - 7, paddleHeight * 0.5);
  } else if (Spressed) {
    paddleY_1 = Math.min(paddleY_1 + 7, canvas.height - paddleHeight * 0.5);
  }

  if (UpPressed) {
    paddleY_2 = Math.max(paddleY_2 - 7, paddleHeight * 0.5);
  } else if (DownPressed) {
    paddleY_2 = Math.min(paddleY_2 + 7, canvas.height - paddleHeight * 0.5);
  }

  // Move the ball
  moveBall();

  // Sync the 2D Positions with 3D Positions
  if (paddleLeftMesh)
  {
    paddleLeftMesh.position.y = paddleY_1;
  }
  if (paddleRightMesh)
    {
    paddleRightMesh.position.y = paddleY_2;
  }

  if (ballMesh)
  {
    ballMesh.position.x = x;
    ballMesh.position.y = y;
  }

}


let interval = null;
function startGame() {
  interval = setInterval(draw, 10);
}

// Button triggers 3D init + 2D loop
document.getElementById("runButton").addEventListener("click", function () {
  init3D();
  resetBall(1);  // Randomize the start
  startGame();
  this.disabled = true;
});
