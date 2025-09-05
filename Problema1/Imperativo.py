# IMPERATIVO

# Lista de estudiantes
estudiantes = [
    ("Angel", 4.9),
    ("Luis", 4.2),
    ("David", 3.5),
    ("Maria", 4.8),
    ("Juan", 4.2),
    ("Sofia", 2.8),
    ("Carlos", 1.2),
    ("Mariana", 3.5),
    ("Miguel", 4.8),
    ("Valentina", 2.8)
]

# Ordenamiento con bucles
for i in range(len(estudiantes)):
    for j in range(i + 1, len(estudiantes)):

        # Comparacion de notas (descendente)
        if (estudiantes[j][1] > estudiantes[i][1]) or \
           (estudiantes[j][1] == estudiantes[i][1] and estudiantes[j][0] < estudiantes[i][0]):
            
            # Intercambio de posiciones
            estudiantes[i], estudiantes[j] = estudiantes[j], estudiantes[i]

print("Ordenamiento imperativo:", estudiantes)