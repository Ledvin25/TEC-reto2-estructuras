using System;

public class NodoAVL
{
    public int Valor { get; set; }
    public int Altura { get; set; }
    public NodoAVL Izquierda { get; set; }
    public NodoAVL Derecha { get; set; }

    public NodoAVL(int valor)
    {
        Valor = valor;
        Altura = 1;
        Izquierda = null;
        Derecha = null;
    }
}

public class ArbolAVL
{
    private NodoAVL Raiz;

    public ArbolAVL()
    {
        Raiz = null;
    }

    // Obtener la altura de un nodo en el árbol AVL
    private int Altura(NodoAVL nodo)
    {
        if (nodo == null)
            return 0;
        return nodo.Altura;
    }

    // Calcular el factor de balance de un nodo en el árbol AVL
    private int Balance(NodoAVL nodo)
    {
        if (nodo == null)
            return 0;
        return Altura(nodo.Izquierda) - Altura(nodo.Derecha);
    }

    // Realizar una rotación a la derecha en el nodo y
    private NodoAVL RotarDerecha(NodoAVL y)
    {
        NodoAVL x = y.Izquierda;
        NodoAVL t2 = x.Derecha;

        x.Derecha = y;
        y.Izquierda = t2;

        y.Altura = Math.Max(Altura(y.Izquierda), Altura(y.Derecha)) + 1;
        x.Altura = Math.Max(Altura(x.Izquierda), Altura(x.Derecha)) + 1;

        return x;
    }

    // Realizar una rotación a la izquierda en el nodo x
    private NodoAVL RotarIzquierda(NodoAVL x)
    {
        NodoAVL y = x.Derecha;
        NodoAVL t2 = y.Izquierda;

        y.Izquierda = x;
        x.Derecha = t2;

        x.Altura = Math.Max(Altura(x.Izquierda), Altura(x.Derecha)) + 1;
        y.Altura = Math.Max(Altura(y.Izquierda), Altura(y.Derecha)) + 1;

        return y;
    }

    // Insertar un valor en el árbol AVL con la raíz especificada
    private NodoAVL Insertar(NodoAVL raiz, int valor)
    {
        if (raiz == null)
            return new NodoAVL(valor);

        if (valor < raiz.Valor)
            raiz.Izquierda = Insertar(raiz.Izquierda, valor);
        else if (valor > raiz.Valor)
            raiz.Derecha = Insertar(raiz.Derecha, valor);

        raiz.Altura = 1 + Math.Max(Altura(raiz.Izquierda), Altura(raiz.Derecha));

        int balance = Balance(raiz);

        // Casos de desequilibrio

        // Caso izquierda-izquierda
        if (balance > 1 && valor < raiz.Izquierda.Valor)
            return RotarDerecha(raiz);

        // Caso derecha-derecha
        if (balance < -1 && valor > raiz.Derecha.Valor)
            return RotarIzquierda(raiz);

        // Caso izquierda-derecha
        if (balance > 1 && valor > raiz.Izquierda.Valor)
        {
            raiz.Izquierda = RotarIzquierda(raiz.Izquierda);
            return RotarDerecha(raiz);
        }

        // Caso derecha-izquierda
        if (balance < -1 && valor < raiz.Derecha.Valor)
        {
            raiz.Derecha = RotarDerecha(raiz.Derecha);
            return RotarIzquierda(raiz);
        }

        return raiz;
    }

    // Insertar un valor en el árbol AVL
    public void Insertar(int valor)
    {
        Raiz = Insertar(Raiz, valor);
    }
}
