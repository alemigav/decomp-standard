/* FUN_80076480
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80076480  body 0x80076480..0x8007659b  size 284 B
 * body sha256 6d723552a180983560b4580c8bb9a0cf0e81e827edaca8bc74c3d684779976a4
 * provider record sha256 2e420bf203467240ea63a76503f30d6ce19b2eda407296c66e6e5836ccd578bc
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80076480(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_800e861f;
  if (uVar1 != 0xff) {
    DAT_80119ed8 = DAT_800c52dc + 0x3310U & 0xfffffff0;
    func_0x80004cfc(*(undefined2 *)(&DAT_80116f68 + uVar1 * 2),DAT_80119ed8,1,"ENEM EDT");
    FUN_8004cd88(1);
    if (-1 < DAT_80119eab) {
      FUN_80075608(7,1);
      DAT_80119eab = -1;
    }
    do {
      DAT_80119eab = FUN_800752dc(*(undefined2 *)(&DAT_80116ed8 + uVar1 * 2),7,1);
      DAT_8011a2a0 = (&PTR_DAT_80116ff8)[uVar1];
    } while (DAT_80119eab == -1);
  }
  return;
}
