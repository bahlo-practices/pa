# Testcases

<table>
    <thead>
        <td>Nr</td>
        <td>Beschreibung</td>
        <td>Ausgangszustand</td>
        <td>Testablauf</td>
        <td>Erwartetes Ergebnis</td>
        <td>Tatsächliches Ergebnis</td>
    </thead>
    <tbody>
        <tr>
            <td>1</td>
            <td>Bas Klasse erstellen</td>
            <td></td>
            <td>Bas test1</td>
            <td>Fehler</td>
            <td>Fehler</td>
        </tr>
        <tr>
            <td>2</td>
            <td>Bei einem Element in der einfach Verketteten liste next auf 0 setzen</td>
            <td></td>
            <td>p1.next = 0</td>
            <td>Liste hört nach p1 auf</td>
            <td>Liste hört nach p1 auf</td>
        </tr>
        <tr>
            <td>3</td>
            <td>Ein Element in der Mitte mit einem neuen ersetzen</td>
            <td></td>
            <td>p4.next = test2</td>
            <td>Liste hört nach test2 auf</td>
            <td>Liste hört nach test2 auf</td>
        </tr>
        <tr>
            <td>4</td>
            <td>Einen Int-Wert als nächstes Element in der Liste setzen</td>
            <td></td>
            <td>r1.next = -1</td>
            <td>Fehler weil falscher Typ</td>
            <td>Fehler weil falscher Typ</td>
        </tr>
        <tr>
            <td>5</td>
            <td>Element in der Liste direkt zuweisen</td>
            <td></td>
            <td>test2.next = &Roo(„eins“, 2)</td>
            <td>Fehler</td>
            <td>Fehler</td>
        </tr>
        <tr>
            <td>6</td>
            <td>Element als Zeiger direkt zuweisen</td>
            <td></td>
            <td>test2.next = *Roo(„zwei“, 3)</td>
            <td>Fehler</td>
            <td>Fehler</td>
        </tr>
        <tr>
            <td>7</td>
            <td>Aus einem Erbenden Element print_all() aufrufen</td>
            <td></td>
            <td>test2->print_all()</td>
            <td> Funktioniert einwandfrei</td>
            <td>Fehler, Element ist kein Pointer</td>
        </tr>
        <tr>
            <td>8</td>
            <td>Element am ende mit einem am anfang verketten</td>
            <td></td>
            <td>p4.next = &p3</td>
            <td>Endlosschleife</td>
            <td>Endlosschleife</td>
        </tr>
    </tbody>
</table>
