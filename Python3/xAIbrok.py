import os
from openai import OpenAI
def isInt(i):
    try:
        int(i)
        return True
    except:
        return False
        
XAI_API_KEY = ""
client = OpenAI(
    api_key=XAI_API_KEY,
    base_url="https://api.x.ai/v1",
)
def main():
    menu = -1
    while menu != 0:
        print("MENU BOT: ")
        print("1. Grok Beta")
        print("2. Grok Vision Beta")
        print("0. Thoat")
        menu = input("Vui Long Nhap Lua Chon: ")
        if isInt(menu):
            menu = int(menu)
        else:
            print("Nhap Vao Phai La So")
            continue
        model = ""
        if menu == 0:
            print("Thoat Menu...")
            break
        if menu == 1:
            model = "grok-beta"
        elif menu == 2:
            model = "grok-vision-beta"
        else:
            print("Lua Chon Khong Hop Le")
        if model != "":
            triNho = ""
            while True:
                user_input = input(f"> [ {model} ] Xin Chao, Hoi Gi Do Di ( 0 De Thoat ): ")
                if user_input == "0":
                    break
                if triNho == "":
                    triNho = user_input
                else:
                    triNho = triNho + "<CauHoi>" + user_input
                print("Bot Dang Suy Nghi...")
                content = ""
                if triNho.__contains__("<CauHoi>"):
                    content = f"First of all, remember that I just asked (the word after <CauHoi> and you have returned is the word after <TraLoi> in the order I sent you: {triNho}, don't text back the old question, answer the question new: {user_input}"
                else:
                    content = user_input
                completion = client.chat.completions.create(
                model = model,
                messages=[
                {"role": "system", "content": "You are Grok, a chatbot created by azzphuc, Only using language Vietnamese to reply"},
                {"role": "user", "content": content},
                ],
                )
                contentResult = completion.choices[0].message.content.replace("*","")
                triNho = triNho + "<TraLoi>" + contentResult
                print("> Bot: "+contentResult)
print(" >> xAI Bot By azzphuc")
main()
