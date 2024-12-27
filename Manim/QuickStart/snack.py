import numpy as np
from manim import *

class GreedySnake(Scene):
    def construct(self):
        # 设置参数
        grid_size = 10  # 网格大小
        cell_size = 0.5  # 单元格大小
        snake_color = BLUE  # 蛇的颜色
        food_color = RED  # 食物颜色

        # 创建网格背景
        grid = VGroup()
        for i in range(grid_size + 1):
            # 横向线条
            grid.add(Line(start=LEFT * grid_size * cell_size / 2 + UP * (i - grid_size / 2) * cell_size,
                          end=RIGHT * grid_size * cell_size / 2 + UP * (i - grid_size / 2) * cell_size))
            # 纵向线条
            grid.add(Line(start=UP * grid_size * cell_size / 2 + LEFT * (i - grid_size / 2) * cell_size,
                          end=DOWN * grid_size * cell_size / 2 + LEFT * (i - grid_size / 2) * cell_size))
        self.add(grid)

        # 初始化蛇
        snake = VGroup(*[Square(side_length=cell_size).set_fill(snake_color, opacity=1)
                         for _ in range(3)])
        for i, part in enumerate(snake):
            part.move_to(ORIGIN + RIGHT * (i - 1) * cell_size + DOWN * cell_size / 2 + RIGHT * cell_size / 2)
        self.add(snake)

        # 创建食物
        food = Square(side_length=cell_size).set_fill(food_color, opacity=1)
        food.move_to(ORIGIN + RIGHT * 3 * cell_size + UP * 2 * cell_size + DOWN * cell_size / 2 + RIGHT * cell_size / 2)
        self.add(food)

        # 动画逻辑：蛇移动并吃掉食物
        moves = [RIGHT, RIGHT, UP, UP, LEFT, LEFT, LEFT, LEFT, LEFT, LEFT,DOWN,DOWN]
        for direction in moves:
            head = snake[-1].copy()
            head.shift(direction * cell_size)
            snake.add(head)

            if np.all(head.get_center() == food.get_center()):
                food.move_to(ORIGIN + LEFT * 3 * cell_size + DOWN * 2 * cell_size + DOWN * cell_size / 2 + RIGHT * cell_size / 2)  # 移动食物
            else:
                snake.remove(snake[0])  # 移除蛇尾

            self.play(Transform(snake, snake), run_time=0.5)

        self.wait(1)