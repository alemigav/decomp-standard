/* FUN_801650a0
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x801650a0  body 0x801650a0..0x80165253  size 436 B
 * body sha256 4d723a1460e036983af031a0657796b9f7c8a07c1d95aeda3d8e11641767bbb8
 * provider record sha256 b09ec41072b1a8815356083405be4ed115a6d340ab08511c84ca41381312d3f9
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801650a0(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  char cVar2;
  undefined4 uVar3;
  
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    param_1[0x7a] = 0x17000000;
    if ((*(ushort *)((int)param_1 + 0x2b6) & 4) != 0) {
      param_1[0x7a] = 0x16000000;
    }
    func_0x80089d54(param_1,param_2,param_3,0x100);
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 1;
  case 1:
    if ((*(ushort *)((int)param_1 + 0x1aa) & 0x4000) == 0) {
      *(undefined1 *)((int)param_1 + 6) = 2;
    }
    break;
  case 2:
    uVar1 = func_0x80033604();
    param_1[0x7a] = (uVar1 & 0xf) * 0x10000 + 0x8000f00;
    if ((*(ushort *)((int)param_1 + 0x2b6) & 4) != 0) {
      uVar1 = func_0x80033604();
      param_1[0x7a] = (uVar1 & 0xf) * 0x10000 + 0x9000f00;
    }
    *(undefined1 *)((int)param_1 + 6) = 3;
    if (*(char *)((int)param_1 + 0x2d5) == '\0') {
      uVar1 = func_0x80033604();
      uVar3 = 0xc;
      if ((uVar1 & 1) == 0) {
        uVar1 = func_0x80033604(0xc);
        uVar3 = 10;
        if ((uVar1 & 1) != 0) {
          uVar3 = 0xb;
        }
      }
      func_0x80077d18(uVar3,param_1);
      *(undefined1 *)((int)param_1 + 0x2d5) = 0x96;
    }
  case 3:
    cVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar2;
    break;
  case 4:
    param_1[1] = 0x1010000;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) & 0xfe;
    *param_1 = *param_1 | 0xc000000;
  }
  return;
}
