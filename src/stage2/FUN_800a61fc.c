/* FUN_800a61fc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a61fc  body 0x800a61fc..0x800a6257  size 92 B
 * body sha256 b19b69e1ab863d7b40ec8f5fc8af7156b2dbfa2fdc44f957860986ebeeaac49e
 * provider record sha256 b05a1e8ffc5e8351469ed329b5bda6f6ac2612bf469c690a08fdfe5575b56f2c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_800a61fc(ushort param_1)

{
  float fVar1;
  
  fVar1 = (float)param_1 * 1.0594631;
  if (2.1474836e+09 <= fVar1) {
    return (int)(fVar1 - 2.1474836e+09) & 0xffff;
  }
  return (int)fVar1 & 0xffff;
}
