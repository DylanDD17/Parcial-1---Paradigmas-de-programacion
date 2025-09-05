# DECLARATIVO

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

# Ordenamiento por nombre (alfabetico)
estudiantes.sort(key=lambda x: x[0])

# Ordenamiento por notas (descendente)
estudiantes.sort(key=lambda x: x[1], reverse=True)

print("Ordenamiento declarativo:", estudiantes)