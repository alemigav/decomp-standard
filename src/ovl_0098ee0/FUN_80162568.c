/* FUN_80162568
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80162568  body 0x80162568..0x801626ef  size 392 B
 * body sha256 2845efaddfb8bfe041b1af96e98f5f219c15d10248b9c5187af6920934a7dc96
 * provider record sha256 9b951d50ad801f6ae8365d28ea4e9682ca11646aeff472ff5b0b7745105357a3
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162568(int param_1,int param_2,int param_3,int param_4,uint param_5,uint param_6)

{
  char cVar2;
  uint uVar1;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  iVar6 = *(int *)(param_1 + 0x234);
  uVar4 = 0x24;
  if ((param_6 & 2) != 0) {
    cVar2 = func_0x80033144(param_1,0x800e1130);
    if (cVar2 != '\0') {
      iVar5 = 0x12;
    }
    uVar4 = 0x12;
  }
  if ((param_6 & 1) != 0) {
    uVar4 = 6;
    iVar5 = iVar5 + ((uint)*(byte *)(param_1 + 0x26e) % 3) * 6;
  }
  if (param_2 != 0) {
    do {
      param_2 = param_2 + -1;
      uVar1 = func_0x80033604();
      if (uVar4 == 0) {
        trap(0x1c00);
      }
      iVar3 = (iVar5 + (uVar1 & 0xff) % uVar4) * 0xc;
      func_0x80037780(param_3 << 0x18 | param_4 << 0x10 | param_5,
                      (int)(((uint)*(ushort *)(param_1 + 0x66) +
                            (uint)*(ushort *)(&DAT_80166226 + iVar3)) * 0x10000) >> 0x10,
                      iVar6 + *(int *)(&DAT_80166228 + iVar3) * 0x178 + 0x38);
    } while (param_2 != 0);
  }
  return;
}
