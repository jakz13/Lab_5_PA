#pragma once

class Mesa {
private:
    int numero;
public:
    Mesa(int numero);
    int getNumero() const;
    void agregarMesaAventa();
    Venta* encontrarVenta();
    void confirmarQuitar();
};