/* FUN_80164480
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80164480  body 0x80164480..0x801645f7  size 376 B
 * body sha256 15896165d2ae167c0358bcd8fad59b7cc1f0a5a4dfae2bac785fa0ae22fad835
 * provider record sha256 fc3116f102c26e0929591193f7940f678832d58475930c35b81b0d9bc388a0db
 * callees 10 direct (10 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164480(int param_1)

{
  byte bVar1;
  char cVar3;
  int iVar2;
  int iVar4;
  undefined2 local_20 [2];
  undefined2 local_1c;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  bVar1 = *(byte *)(param_1 + 6);
  iVar4 = *(int *)(param_1 + 0x234);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined4 *)(param_1 + 4) = 0x1010000;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined1 *)(param_1 + 0x2c7) = 200;
    *(undefined2 *)(param_1 + 500) = 0;
  }
  cVar3 = func_0x80036c68(param_1,3,0xf,0);
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar3;
  func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x18);
  local_20[0] = *(undefined2 *)(param_1 + 0x2b8);
  local_1c = *(undefined2 *)(param_1 + 0x2ba);
  iVar2 = FUN_80161e10(param_1,0xc,0x15,0x19,0x2ee);
  if (iVar2 != 0) {
    func_0x80077d18(2,param_1);
    func_0x80052bd0(3,0);
    func_0x80052c6c(8,0xdc,0);
    func_0x80052d10(4,0xdc,0x28,8);
    FUN_8016227c(param_1,local_20,0xc);
    local_18 = *(undefined2 *)(iVar4 + 0x11ee);
    local_16 = *(undefined2 *)(iVar4 + 0x11f2);
    local_14 = *(undefined2 *)(iVar4 + 0x11f6);
    func_0x80037780(0x2400,0,0x800e9028,&local_18);
    FUN_80162114(0x1e);
  }
  return;
}
