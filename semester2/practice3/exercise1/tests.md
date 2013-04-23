# Testfälle

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
            <td>Line erstellen und direkt drawn</td>
            <td></td>
            <td>
                Line line1;<br/>
                line1.draw(&frame1)
            </td>
            <td>Ein Punkt bei 0:0</td>
            <td>Ein Punkt bei 0:0</td>
        </tr>
        <tr>
            <td>2</td>
            <td>Line erstellen mit negativen Koordinaten</td>
            <td></td>
            <td>
                Line line4(0, -10, 0, 0);<br/>
                line4.draw(&frame1);
            </td>
            <td>Fehler: Nicht auf dem Frame</td>
            <td>Ermitteln der Punkte nicht möglich, da Punkte nicht auf Frame</td>
        </tr>
        <tr>
            <td>3</td>
            <td>2 Lines erstellen, die sich kreuzen</td>
            <td></td>
            <td>
                Line line5(3, 0, 10, 10);<br />
                Line line6(3, 10, 10, 0);<br />
                line5.draw(&frame1);<br />
                line6.draw(&frame1);
            </td>
            <td>Kein Fehler</td>
            <td>Kein Fehler</td>
        </tr>
        <tr>
            <td>4</td>
            <td>Eine Line mit nur zwei Parametern erstellen</td>
            <td></td>
            <td>Line line7(100, 20);</td>
            <td>Kein passender Konstruktor</td>
            <td>Kein passender Konstruktor</td>
        </tr>
        <tr>
            <td>5</td>
            <td>Eine Linie von oben rechts nach unten links</td>
            <td></td>
            <td>
                Line line8(0, 99, 99, 0); <br/>
                line8.draw(&frame1);
            </td>
            <td>Kein Fehler</td>
            <td>Kein Fehler</td>
        </tr>
        <tr>
            <td>6</td>
            <td>Ein Dreieck mit dem Standardkonstruktor initialisieren und zeichnen</td>
            <td></td>
            <td>
                Triangle triangle3; <br/>
                triangle3.draw(&frame1);
            </td>
            <td>Dreieck nicht korrekt, weil Standardkonstruktor alles auf 0 setzt</td>
            <td>Dreieck nicht korrekt</td>
        </tr>
        <tr>
            <td>7</td>
            <td>Ein Dreick zeichnen, welches den Frame voll ausfüllt</td>
            <td></td>
            <td>
                Triangle triangle4(50, 99, 99, 0, 0, 0);<br/>
                triangle4.draw(&frame1);
            </td>
            <td>Funktioniert einwandfrei.</td>
            <td>Funktioniert einwandfrei.</td>
        </tr>
        <tr>
            <td>8</td>
            <td>Den Konstruktor mit den Seitenangaben testen</td>
            <td></td>
            <td>
                Triangle triangle5(20, 20, 40, 20, 30);
                triangle5.draw(&frame1);
            </td>
            <td>Funktioniert einwandfrei.</td>
            <td>Funktioniert einwandfrei.</td>
        </tr>
        <tr>
            <td>9</td>
            <td>move() testen</td>
            <td></td>
            <td>
                Triangle triangle6(10, 10, 20, 0, 0, 0);
                triangle6.move(10, 20);
                triangle6.draw(&frame1);
            </td>
            <td>Funktioniert</td>
            <td>Funktioniert</td>
        </tr>
        <tr>
            <td>10</td>
            <td>move() nach unten rechts (negative Werte)</td>
            <td></td>
            <td>
                Triangle triangle7(40, 50, 60, 30, 30, 30);
                triangle7.move(-20, -10);
                triangle7.draw(&frame1);
            </td>
            <td>Funktioniert, solange im Frame</td>
            <td>Funktioniert, solange im Frame</td>
        </tr>
    </tbody>
</table>
