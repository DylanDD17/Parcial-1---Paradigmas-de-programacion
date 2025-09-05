# Parcial-1---Paradigmas-de-programacion
# PROBLEMA 1:
# Análisis comparativo: Programación Imperativa vs Declarativa

Este proyecto implementa un programa en **Python** que ordena una lista de estudiantes según su nota (de mayor a menor) y, en caso de empate, por orden alfabético de sus nombres.  
Se presentan dos enfoques: **imperativo** y **declarativo**.


##  1. Claridad y legibilidad del código
- **Imperativo:** muestra cada paso del ordenamiento mediante bucles y condiciones. Es más largo y menos legible, ya que hay que seguir la lógica línea por línea.  
- **Declarativo:** se resuelve en pocas líneas con `sort()`. La intención del programa es clara y directa.  


##  2. Nivel de expresividad y abstracción
- **Imperativo:** describe *cómo* se hace el ordenamiento (detalles de comparaciones e intercambios).  
- **Declarativo:** describe *qué* se quiere lograr (ordenar por nota y luego por nombre).  


##  3. Manejo de estructuras de datos
- **Imperativo:** muta directamente la lista mediante intercambios.  
- **Declarativo:** muta la lista usando `.sort()`, ocultando los detalles internos.  


##  4. Manejo de estado
- **Imperativo:** el estado de la lista cambia paso a paso en cada iteración y el programador debe controlarlo.  
- **Declarativo:** el manejo del estado está abstraído y solo interesa el resultado final.  


## 5. Facilidad de mantenimiento y extensión
- **Imperativo:** añadir nuevas reglas de ordenamiento implica modificar condiciones dentro de los bucles, aumentando la complejidad.  
- **Declarativo:** basta con modificar el `key` de `sort()` o añadir otro criterio.  


##  6. Eficiencia
- **Imperativo:** al implementarse manualmente con bucles anidados, el programa realiza muchas comparaciones e intercambios innecesarios. Esto funciona bien con listas pequeñas, pero se vuelve lento en listas grandes.  
- **Declarativo:** aprovecha las optimizaciones internas de Python, que están escritas en C y probadas en millones de casos. Esto le permite manejar listas extensas de manera mucho más rápida y confiable.  


##  Conclusión
- El **enfoque imperativo** es útil para comprender cómo funcionan los algoritmos internamente, pero es más complejo, menos eficiente y difícil de mantener.  
- El **enfoque declarativo** es más claro, conciso, expresivo, eficiente y fácil de modificar.  

---

# PROBLEMA 2:
# Sistema de Gestión de Estudiantes en C (Optimización de Memoria)

Este proyecto implementa un sistema básico de gestión de estudiantes en **C**, con énfasis en el **uso eficiente de memoria dinámica**.  
El objetivo es almacenar registros de estudiantes de forma optimizada, cumpliendo con los siguientes requisitos:  

1. **Creación de Estudiantes**  
   - Se reserva memoria dinámica para la estructura `Estudiante` usando `malloc`.  
   - Se asigna memoria exacta para el `nombre` y `apellido` usando `strlen(nombre) + 1`.  
   - Se reserva un array dinámico de calificaciones usando `malloc(num * sizeof(float))`.  
   - Se copian los datos en la memoria recién asignada.

2. **Visualización de Datos**  
   - Se recorre el arreglo de punteros a estudiantes.  
   - Solo se imprimen los estudiantes que **no son `NULL`**, mostrando nombre, edad, ID y calificaciones.  

3. **Liberación de Memoria**  
   - Se libera primero la memoria de `nombre`, `apellido` y `calificaciones`.  
   - Luego se libera la memoria de la estructura `Estudiante`.  
   - Finalmente, el puntero se establece en `NULL` para evitar punteros colgantes y permitir que la lista ignore ese espacio.

4. **Compactación Lógica**  
   - Al liberar un estudiante, su posición en el arreglo se vuelve `NULL`.  
   - Esto asegura que el programa no intente acceder a memoria liberada y mantiene la lista consistente al imprimir solo registros válidos.

##  Claves para la solucion:
- **Uso de `malloc` y `free`** para asignación y liberación de memoria dinámica.  
- **Punteros `NULL`** después de `free` para evitar errores de acceso.  
- **Bitfields** en la estructura para optimizar el espacio de `edad` e `id`.  
- **Memoria exacta** para cadenas y arrays, evitando "desperdicio".

---

# PROBLEMA 3: 
# Cálculo Lambda – Implementación del Promedio

Este ejercicio muestra cómo expresar en **cálculo lambda** la función para calcular el promedio de una lista de números en Haskell.


## Código Haskell Original

```haskell
promedio xs = realToFrac (sum xs) / genericLength xs

main :: IO ()
main = do
  putStrLn "Ingrese una lista de números separados por espacios:"
  entrada <- getLine
  let numeros = map read (words entrada) :: [Double]
  if null numeros
    then putStrLn "La lista está vacía, no se puede calcular el promedio."
    else putStrLn $ "El promedio es: " ++ show (promedio numeros)
```
**Representación Matemática**

**promedio(L) = suma(L) / longitud(L)**

**Notación de Cálculo Lambda**

**λL → (foldr (+) 0 L) / (length L)**

Explicación :
- λL → define una función que recibe una lista L
- foldr (+) 0 L → suma todos los elementos de la lista usando reducción por la derecha
- length L → obtiene el tamaño de la lista
- División → calcula el promedio al dividir la suma entre la longitud

# Ejemplo de Uso con Función Lambda:
```haskell
main :: IO ()
main = do
  putStrLn "Ingrese una lista de números separados por espacios:"
  entrada <- getLine
  let numeros = map read (words entrada) :: [Double]
  if null numeros
    then putStrLn "La lista está vacía, no se puede calcular el promedio."
    else putStrLn $ "El promedio es: " ++ show ((\xs -> realToFrac (sum xs) / genericLength xs) numeros)
```
