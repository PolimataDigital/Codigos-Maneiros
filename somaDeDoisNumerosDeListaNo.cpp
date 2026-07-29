//Baseado no exercício "Somar dois números" do LeetCode


truct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;   // vai guardar o primeiro nó do resultado (o que retornamos no final)
        ListNode* cursor = nullptr; // "cursor" que anda apontando pro último nó já criado

        int carry = 0; // o "vai um" da soma

        // continua enquanto ainda tiver dígito em l1, OU em l2, OU sobrar carry
        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            
            // pega o dígito atual de cada lista, ou 0 se essa lista já acabou
            int valorL1 = (l1 != nullptr) ? l1->val : 0;
            int valorL2 = (l2 != nullptr) ? l2->val : 0;

            int soma = valorL1 + valorL2 + carry;

            int novoDigito = soma % 10; // o que sobra pra escrever nessa posição
            carry = soma / 10;          // o que "vai" pra próxima posição

            ListNode* novoNo = new ListNode(novoDigito); // cria o nó com esse dígito

            if (head == nullptr) {
                // é o primeiro nó da lista resultado
                head = novoNo;
                cursor = novoNo;
            } else {
                // conecta o novo nó no final da lista, e avança o cursor
                cursor->next = novoNo;
                cursor = novoNo;
            }

            // avança cada lista original, só se ela ainda não tiver acabado
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return head; // devolve o primeiro nó — a lista inteira é acessível a partir dele
    }
};
