def diagnose(symptoms):
    symptoms = [s.lower() for s in symptoms]


    if "fever" in symptoms and "cough" in symptoms:
        return {
            "disease": "Flu",
            "doctor": "General Physician",
            "advice": "Take rest, drink fluids, and take paracetamol."
        }

    elif "fever" in symptoms and "headache" in symptoms and "body pain" in symptoms:
        return {
            "disease": "Dengue",
            "doctor": "Physician",
            "advice": "Get blood test done immediately and stay hydrated."
        }

    elif "chest pain" in symptoms:
        return {
            "disease": "Possible Heart Problem",
            "doctor": "Cardiologist",
            "advice": "Seek immediate medical attention."
        }

    elif "stomach pain" in symptoms and "vomiting" in symptoms:
        return {
            "disease": "Food Poisoning",
            "doctor": "Gastroenterologist",
            "advice": "Drink ORS and avoid outside food."
        }

    elif "rash" in symptoms:
        return {
            "disease": "Allergy",
            "doctor": "Dermatologist",
            "advice": "Avoid allergens and use antihistamines."
        }

    else:
        return {
            "disease": "Unknown",
            "doctor": "General Physician",
            "advice": "Please consult a doctor for proper diagnosis."
        }


def start_system():
    print("Hospital Expert System")
    print("Enter symptoms separated by comma (e.g., fever, cough):")
    
    user_input = input("Symptoms: ")
    symptoms = user_input.split(",")

    result = diagnose(symptoms)

    print("\n--- Diagnosis Result ---")
    print("Possible Disease:", result["disease"])
    print("Recommended Doctor:", result["doctor"])
    print("Advice:", result["advice"])


if __name__ == "__main__":
    start_system()