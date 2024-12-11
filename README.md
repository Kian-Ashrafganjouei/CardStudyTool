# Study Cards Project

This project is a command-line tool for studying flashcards using C++. The tool reads questions and answers from a `flashcards.json` file and allows users to study them interactively. The system also tracks the user's performance on each question to prioritize harder questions.

---

## **Project Structure**
```
study-cards/
├── flashcards.json         # JSON file containing the flashcards (questions, answers, and scores)
├── json/                   # Directory containing nlohmann/json CMake project
├── main.cpp                # Main C++ file
├── CMakeLists.txt          # CMake configuration file
├── Makefile                # Makefile for building the project
└── README.md               # This README file
```

---

## **Prerequisites**
Make sure you have the following installed:
- **CMake** (version 3.10 or higher)
- **Make** (for the build system)
- **g++** (C++17 or higher)
- **nlohmann/json** (included as a submodule or directory in this project)

---

## **How to Run**

1. **Clone the Repository** and move into the project directory:
   ```bash
   git clone <your-repo-url> study-cards
   cd study-cards
   ```

2. **Build the Project** using the provided `Makefile`:
   ```bash
   make
   ```

3. **Move the flashcards.json file** to the build directory (optional):
   ```bash
   make move-json
   ```

4. **Run the Study Cards program** from the `build/` directory:
   ```bash
   cd build
   ./StudyCards
   ```

---

## **Commands Reference**

| **Command**         | **Description**                                         |
|--------------------|-------------------------------------------------------|
| `make`             | Compiles and builds the entire project using CMake.      |
| `make move-json`   | Moves `flashcards.json` to the `build/` directory.       |
| `make clean`       | Cleans the `build/` directory.    |
| `cd build`         | Changes directory to `build/`, where the executable is. |
| `./StudyCards`     | Runs the compiled StudyCards program.                    |

---

## **Example flashcards.json**

Here is an example of what `flashcards.json` should look like:
```json
{
    "flashcards": [
        {
            "question": "What is the capital of France?",
            "answer": "Paris",
            "score": 0
        },
        {
            "question": "What is 2 + 2?",
            "answer": "4",
            "score": 0
        },
        {
            "question": "Who wrote 'To Kill a Mockingbird'?",
            "answer": "Harper Lee",
            "score": 0
        },
        {
            "question": "What is the largest planet in our solar system?",
            "answer": "Jupiter",
            "score": 0
        }
    ]
}
```

---

## **Features**
- **Randomized Questions**: Questions are presented in a randomized order, with lower-score flashcards having higher priority.
- **Difficulty-Based Progress**: After answering, you rate the question as Easy, Hard, or Wrong. The score is updated accordingly.
- **Automatic Progress Saving**: After each session, your progress is saved to `flashcards.json`.
- **CMake Integration**: Uses CMake to manage the build system.
- **Makefile for Automation**: Includes commands for building, cleaning, and moving necessary files.

---

## **Possible Improvements**
- **Custom Score Weights**: Allow customization of the scoring system.
- **Dynamic File Paths**: Option to specify custom paths for `flashcards.json`.
- **User Interface**: Add support for a graphical user interface (GUI) version.

---

## **License**
This project is licensed under the MIT License. Feel free to use, modify, and distribute.

---

## **Contact**
For any questions or suggestions, feel free to reach out.
kian Ashrafganjouei (kian.ashrafganjouei@gmail.com)

Enjoy your study session! 📚🚀
