# Let's create a text file named "tentativi.txt" containing multiple words, 
# with one specific word to check against a solution.

words = [
    "parco", "carte", "abbia", "input", "perla",
    "fuoco", "treno", "mela", "torre", "punta",
    "lupin", "sogno", "piano", "vento", "suono",
    "fiore", "latte", "frutto", "gioco", "ombra",
    "leone", "strada", "tenda", "cassa", "burro"
]

# Write these words into "tentativi.txt"
with open("./tentativi.txt", "w") as file:
    for word in words:
        file.write(word + "\n")

# Specific word for the check (e.g., "torre" from the example)
solution_word = "torre"

solution_word