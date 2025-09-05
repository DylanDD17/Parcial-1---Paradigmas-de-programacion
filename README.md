# Parcial-1---Paradigmas-de-programacion
# Análisis comparativo: Programación Imperativa vs Declarativa

Este proyecto implementa un programa en **Python** que ordena una lista de estudiantes según su nota (de mayor a menor) y, en caso de empate, por orden alfabético de sus nombres.  
Se presentan dos enfoques: **imperativo** y **declarativo**.

---

##  1. Claridad y legibilidad del código
- **Imperativo:** muestra cada paso del ordenamiento mediante bucles y condiciones. Es más largo y menos legible, ya que hay que seguir la lógica línea por línea.  
- **Declarativo:** se resuelve en pocas líneas con `sort()`. La intención del programa es clara y directa.  

---

##  2. Nivel de expresividad y abstracción
- **Imperativo:** describe *cómo* se hace el ordenamiento (detalles de comparaciones e intercambios).  
- **Declarativo:** describe *qué* se quiere lograr (ordenar por nota y luego por nombre).  

---

##  3. Manejo de estructuras de datos
- **Imperativo:** muta directamente la lista mediante intercambios.  
- **Declarativo:** muta la lista usando `.sort()`, ocultando los detalles internos.  

---

##  4. Manejo de estado
- **Imperativo:** el estado de la lista cambia paso a paso en cada iteración y el programador debe controlarlo.  
- **Declarativo:** el manejo del estado está abstraído y solo interesa el resultado final.  

---

## 5. Facilidad de mantenimiento y extensión
- **Imperativo:** añadir nuevas reglas de ordenamiento implica modificar condiciones dentro de los bucles, aumentando la complejidad.  
- **Declarativo:** basta con modificar el `key` de `sort()` o añadir otro criterio.  

---

##  6. Eficiencia
- **Imperativo:** al implementarse manualmente con bucles anidados, el programa realiza muchas comparaciones e intercambios innecesarios. Esto funciona bien con listas pequeñas, pero se vuelve lento en listas grandes.  
- **Declarativo:** aprovecha las optimizaciones internas de Python, que están escritas en C y probadas en millones de casos. Esto le permite manejar listas extensas de manera mucho más rápida y confiable.  

---

##  Conclusión
- El **enfoque imperativo** es útil para comprender cómo funcionan los algoritmos internamente, pero es más complejo, menos eficiente y difícil de mantener.  
- El **enfoque declarativo** es más claro, conciso, expresivo, eficiente y fácil de modificar.  
