"""

har cashier be yek queue dare eshare mikone (yani sare vaghte oone)
alan too dequeue bayad oon queue ee az shop kam beshe ke cashier_id dare
    behesh eshare mikone
farz kon ye list 2 ozve darim
cashiers = [?, ?] ke moshakhas mikone har cashier be ye queue az moshtaria
    eshare mikone


dar kol too in soal bayad harchi ke niaz dari ro baraye khodet tarif koni :D
nabayad hatman piadash koni kamel
faghat barnamat kar kone kamel mishe nomrat

function dequeue(ref Q: queue, cashier_id: int) : String {
    q = cashiers[cashier_id] # inja q safi ro maloom mikone ke aghaye cashier_id sare oone
    
    return q.dequeue().name
    # nega kon inja q.dequeue function ADT e bara q. ba in function line 15 ghaati nakon
}

inja bayad moshtarie jadid ro add konim

function enqueue(ref Q: queue, wieght: Real, name: String) {
    # ya vojood dare ya nadare

    trav = Q.head()

    while (trav != Q.rear()) {
        if (trav.weight == wieght) {
            # inja peyda kardim queue ro chon vojod dare
            # Inja niaz be class Customer darim
            trav.enqueue(new Customer(name, weight))
            return
        }

        if (trav.weight > weight and trav.next.weight < weight) {
            # Inja peyda nmishe chon vojood nadare
            # age vojood dashte in shart bar gharar nmishod (too if ghabli return mishodim)
            Queue temp = trav.next
            trav.next = new Queue(weight)
            trav.next.next = temp

            trav.next.enqueue(weight)
        }

        trav = trav.next
    }
}




"""