#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define WID 64
#define HEI 32
class node
{
  public:
  int x,y,dir;
};
class Snake
{
  public:
  node m_snake[100];
  int size;
  Snake();
  void push();
  void Init();
  void Move();
  void Draw();
};
