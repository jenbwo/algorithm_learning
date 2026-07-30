class MyQueue:

    def __init__(self):
        self.stack_in = []  #   模拟输入栈
        self.stack_ot = []  #   模拟输出栈

    def push(self, x: int) -> None:
        self.stack_in.append(x)

    def pop(self) -> int:
        #   模拟队列操作，从输入栈一个一个取出来放入输出栈，最后再从输出栈中弹出来
        #   首先输出栈要为空，才把元素放进去
        if not self.stack_ot:
            while self.stack_in:
                self.stack_ot.append(self.stack_in.pop())
        return self.stack_ot.pop()

    def peek(self) -> int:
        res = self.pop()
        self.stack_ot.append(res)
        return res
        

    def empty(self) -> bool:
        #   当输入栈和输出栈都是空的，栈才是空的
        return not self.stack_in and not self.stack_ot


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()