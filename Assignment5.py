import nltk
from nltk.chat.util import Chat, reflections

pairs = [

    [
        r"hi|hello|hey",
        ["Hello! Welcome to ABC Bank. How can I assist you today?",
         "Hi there! How can I help you?"]
    ],

    [
        r"my name is (.*)",
        ["Hello %1, nice to meet you! How can I help you today?"]
    ],

    [
        r"(.*) balance (.*)",
        ["Please log in to your account to check your balance.",
         "You can check your balance using our mobile app or website."]
    ],

    [
        r"(.*) loan (.*)",
        ["We offer home, personal, and car loans. Which one are you interested in?",
         "You can apply for loans directly from our website."]
    ],

    [
        r"(.*) card (lost|stolen|block)(.*)",
        ["Please call our helpline immediately at 1800-123-456 to block your card.",
         "Your card safety is important. Contact customer care to block it."]
    ],
    
    [
        r"(.*) open account (.*)",
        ["You can open an account online or visit your nearest branch with valid ID proof."]
    ],

    [
        r"(.*) working hours (.*)",
        ["Our bank operates from 9 AM to 5 PM, Monday to Friday."]
    ],

    [
        r"thank you|thanks",
        ["You're welcome!", "Happy to help!"]
    ],

    [
        r"how are you ?",
        ["I am just a bot, but I am doing great! How can I help you?"]
    ],

    [
        r"bye|exit|quit",
        ["Goodbye! Have a great day.", "Thank you for visiting ABC Bank!"]
    ],

    [
        r"(.*)",
        ["I'm sorry, I didn't understand that. Could you please rephrase?",
         "Can you please provide more details?"]
    ]
]

chatbot = Chat(pairs, reflections)

def start_chat():
    print("Welcome to ABC Bank Chatbot! (type 'bye' to exit)")
    chatbot.converse()

if __name__ == "__main__":
    start_chat()