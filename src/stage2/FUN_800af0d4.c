/* FUN_800af0d4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800af0d4  body 0x800af0d4..0x800af12f  size 92 B
 * body sha256 864def80bb08f9dbb197023ac4aa597580da566e81aaf00b5b02b12bde935e7f
 * provider record sha256 637bdd23bd21a20e3ff44d87b780ea174b5a924c99d6f9d204b44a343000acd3
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_800af0d4(uint param_1)

{
  int *piVar1;
  int *piVar2;
  
  if (param_1 != 0xffffffff) {
    piVar1 = (int *)0x0;
    piVar2 = _DAT_80158430;
    if (_DAT_80158430 != (int *)0x0) {
      while (piVar2[2] != param_1) {
        piVar1 = (int *)0x0;
        if ((param_1 < (uint)piVar2[2]) || (piVar2 = (int *)*piVar2, piVar2 == (int *)0x0))
        goto LAB_800af10c;
      }
      piVar1 = piVar2;
    }
LAB_800af10c:
    if (piVar1 != (int *)0x0) {
      return piVar1[3];
    }
  }
  return -1;
}
