.name "42"
.comment "Just a basic Winner Program"

entry:  live    %42
        fork    %:func0
        ld      %0, r5
        zjmp    %281

func0:  sti     r1, %:func3, %1
        ld      %2304, r10
        ld      %1, r5
        ld      %0, r11
        ld      %4, r3

func1:  live    %42
        fork    %:func2
        live    %742
        sub     r3, r5, r3
        zjmp    %:start
        ld      %0, r11
        fork    %212
        live    %42
        sti     r10, %-510, %0
        sti     r10, %-404, %0
        sti     r10, %-303, %0
        sti     r10, %-202, %0
        ld      %0, r11
        zjmp    %:func1

func2:  ld      %368, r2
        ld      %0, r3
        ld      %4, r4

func3:  live    %1
        sti     r10, %-510, r2
        sti     r10, %-510, r3
        add     r4, r5, r4
        add     r3, r4, r3
        sub     r2, r4, r2
        zjmp    %:func2
        ld      %0, r11
        zjmp    %:func3
        zjmp    %293

jump0:  zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0

func9:  sub     r6, r4, r6
        add     r6, r6, r11
        ldi     %:jump0, r6, r7
        sti     r7, %-510, r11

func5:  live    %1
        ld      %0, r10
        sti     r7, %-250, r6
        zjmp    %-192
        zjmp    %376
        sti     r1, %:cpy, %2
        ldi     %:cpy, %3, r2
        sti     r2, %:entry, %-4
        ldi     %:cpy, %-1, r2
        sti     r2, %:entry, %-8
        sti     r1, %:func5, %1
        sti     r1, %:func6, %1
        ld      %0, r2
        ld      %8, r3
        ld      %1, r4
        ld      %0, r6
        
func6:  live    %1
        sub     r3, r4, r3
        zjmp    %:case
        fork    %:func8
        st      r5, r2
        xor     r10, r10, r10
        add     r10, r10, r10
        add     r6, r6, r6
        ld      %0, r10
        zjmp    %:func6
        
func8:  add     r2, r4, r2
        add     r6, r6, r6
        add     r6, r4, r6
        ld      %0, r10
        zjmp    %:func6
        
start:  live    %42
        ld      %9, r3
        sti     r3, %:jump0, %-6
        ld      %2, r3
        sti     r3, %:jump0, %-16
        ld      %0, r3
        zjmp    %:st_cll

func7:  sti     r1, %:live0, %1
        sti     r1, %:live1, %1
        sti     r1, %:live2, %1
        sti     r1, %:live3, %1
        sti     r1, %:live4, %1
        sti     r1, %:live5, %1
        sti     r1, %:live6, %1
        sti     r1, %:live7, %1
        sti     r1, %:live8, %1
        sti     r1, %:live9, %1
        sti     r1, %:live10, %1

live0:  live    %1
live1:  live    %1
live2:  live    %1
live3:  live    %1
live4:  live    %1
live5:  live    %1
live6:  live    %1
live7:  live    %1
live8:  live    %1
live9:  live    %1
live10: live    %1
        zjmp    %:live0
        zjmp    %:func7
        live    %0

cpy:    ld      %1, r1

case:   sti     r1, %:call0, %1
        or      r2, r2, r2
        zjmp    %:call3
        sub     r2, r4, r2
        zjmp    %:func9
        ld      %0, r2
        zjmp    %:func7
        zjmp    %:call4
        
st_cll: ld      %9, r3
        sti     r3 ,%:end , %-6
        ld      %2, r3
        sti     r3, %:end, %-16
        ld      %0, r3
        zjmp    %:func7
        
jump1:  zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0
        zjmp    %0

call3:  ld      %10, r8
        sub     r6, r8, r6
        and     r6, %2147483648, r8
        zjmp    %:call2
        ld      %118, r8
        add     r6, r8, r6

call2:  add     r6, r6, r6
        ld      %272, r8
        ld      %29, r9
        ldi     %:jump1, r6, r7
        sti     r7, r8, r6
        sti     r7, r9, r6

call0:  live    %1
        ld      %0, r10
        zjmp    %186

call4:  ld      %425, r2
        ld      %0, r3
        ld      %4, r4

call1:  live    %42
        sti     r10, %:end, r2
        sti     r10, %:end, r3
        add     r4, r5, r4
        add     r3, r4, r3
        sub     r2, r4, r2
        zjmp    %:call4
        ld      %0, r11
        zjmp    %:call1
        zjmp    %-360

end:    live    %633
