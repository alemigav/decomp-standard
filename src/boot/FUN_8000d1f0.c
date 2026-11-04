/* FUN_8000d1f0
 * image   boot (boot), base 0x80000480
 * address 0x8000d1f0  body 0x8000d1f0..0x8000d2a7  size 184 B
 * body sha256 8dfa01697c45abfb93a9257553f4f4e2ee9f8ae0596b13ffdb0f23d8e14a568d
 * provider record sha256 78324b9af538be577915b4a6ca1903b79a88e1ecadae68b980b71a7285ee7414
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8000d1f0(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if ((param_2 & 3) != 0) {
    FUN_8000c620(0x80011ca0,0x80011ca4,0x37);
  }
  iVar1 = FUN_8000d2b0();
  uVar2 = 0xffffffff;
  if (iVar1 == 0) {
    if (param_1 == 1) {
      FUN_8000efa0(param_2,0x40);
    }
    _DAT_a4800000 = FUN_8000e800(param_2);
    if (param_1 == 0) {
      puVar3 = (undefined4 *)&DAT_a4800004;
    }
    else {
      puVar3 = (undefined4 *)&DAT_a4800010;
    }
    *puVar3 = 0x1fc007c0;
    uVar2 = 0;
    if (param_1 == 0) {
      FUN_80007320(param_2,0x40);
      uVar2 = 0;
    }
  }
  return uVar2;
}
