/* FUN_801653c4
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x801653c4  body 0x801653c4..0x80165567  size 420 B
 * body sha256 4a49ab4c29391737d7037908905718acde0c02cc3e8813116284f8a30c553ba3
 * provider record sha256 8af2b10f82f440d6867a6fe5bba074ecf534452bbbeda58538bd7163018e4c10
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801653c4(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      _DAT_800e1196 = _DAT_800e1196 + 0x800;
      func_0x8003331c(param_1,param_2,param_3,0);
      _DAT_800e1196 = _DAT_800e1196 + -0x800;
      iVar2 = func_0x80089d54(param_1,param_2,param_3,0x200);
      if (iVar2 == 0) {
        return;
      }
      *(undefined1 *)(param_1 + 6) = 3;
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0x700;
    *(undefined1 *)(param_1 + 6) = 1;
    _DAT_800e110c = _DAT_800e110c | 0x40;
    *(undefined1 *)(param_1 + 0x25c) = 1;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    func_0x80077adc(0x4010001,param_1 + 0x28);
  }
  *(int *)(param_1 + 0x28) =
       *(int *)(param_1 + 0x28) + ((int)*(short *)(param_1 + 0x200) - *(int *)(param_1 + 0x28) >> 1)
  ;
  *(int *)(param_1 + 0x30) =
       *(int *)(param_1 + 0x30) + ((int)*(short *)(param_1 + 0x204) - *(int *)(param_1 + 0x30) >> 1)
  ;
  func_0x80032ef4(param_1,(int)*(short *)(param_1 + 0x1f6),0x100);
  func_0x80089d54(param_1,param_2,param_3,0x200);
  if (*(char *)(param_1 + 0x1e9) == '\b') {
    *(undefined1 *)(param_1 + 6) = 2;
    *(undefined2 *)(param_1 + 0x66) = *(undefined2 *)(param_1 + 0x1f6);
    func_0x80077adc(0x4010001,param_1 + 0x28);
  }
  return;
}
