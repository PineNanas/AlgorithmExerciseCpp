class Solution:
    def decodeString(self, s: str) -> str:
        stack: list[str] = []
        str_builder: list[str] = []
        for c in s:
            if c != ']':
                stack.append(c)
            else:
                str_builder.clear()
                while stack and stack[-1] != '[':
                    str_builder.append(stack.pop())
                stack.pop()
                cur_str: str = ''.join(str_builder[::-1])
                num_builder: list[str] = []
                while stack and stack[-1].isdigit():
                    num_builder.append(stack.pop())
                num: int = int(''.join(num_builder[::-1]))
                cur_str = cur_str * num
                stack.append(cur_str)
        return ''.join(stack)
