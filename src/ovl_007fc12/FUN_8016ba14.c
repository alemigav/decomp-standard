/* FUN_8016ba14
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016ba14  body 0x8016ba14..0x8016bc2f  size 540 B
 * body sha256 95a969c9699a82963c7d859761f3c80be3054fcdbf4378c37d7a490a73deccfa
 * provider record sha256 8c958b760b02533546d4d5cad3b3f5ef4ccb327af2845de4b8cdc79bd123d6fc
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016ba14(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  undefined2 local_28;
  short local_26;
  undefined2 local_24;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined4 *)(param_1 + 4) = 0x7000000;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    iVar3 = *(int *)(param_1 + 0x234);
    *(undefined4 *)(param_1 + 0x1e8) = 0x20a0300;
    *(undefined1 *)(param_1 + 0x206) = 1;
    *(undefined1 *)(param_1 + 6) = 1;
    *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 4;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    local_28 = *(undefined2 *)(iVar3 + 0xbde);
    local_26 = *(short *)(iVar3 + 0xbe2) + 300;
    local_24 = *(undefined2 *)(iVar3 + 0xbe6);
    iVar3 = *(int *)(param_1 + 0x234) + 0x38;
    func_0x80037780(8000,(int)*(short *)(param_1 + 0x66),iVar3,&local_28);
    local_26 = local_26 + -400;
    func_0x80037780(0x8001b58,(int)*(short *)(param_1 + 0x66),iVar3,&local_28);
    func_0x80037780(0x21f40,(int)*(short *)(param_1 + 0x66),iVar3,&local_28);
    iVar3 = *(int *)(param_1 + 0x234);
    *(undefined1 *)(param_1 + 0x25c) = 1;
    uVar4 = *(uint *)(iVar3 + 0xbc0);
    if ((DAT_800e9012 & 8) != 0) {
      uVar4 = uVar4 | 0x4a;
    }
    *(uint *)(iVar3 + 0xbc0) = uVar4;
    *(undefined2 *)(iVar3 + 0xcf2) = 0xff9c;
    *(undefined2 *)(iVar3 + 0xcf0) = 0;
    *(undefined2 *)(iVar3 + 0xcf8) = 0;
    *(undefined2 *)(iVar3 + 0xcf4) = 0;
    *(undefined2 *)(iVar3 + 0xcf6) = 10;
    *(undefined2 *)(iVar3 + 0xcfc) = 0;
    *(undefined4 *)(iVar3 + 0xc20) = 0x101040;
    puVar5 = *(uint **)(param_1 + 0x234);
    puVar5[0x4c] = 0x40;
    puVar5[0x4d] = 0x101010;
    *puVar5 = *puVar5 | 0x80;
    func_0x80077d18(2,param_1);
    func_0x80035b84(param_1);
  }
  cVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar2;
  if (*(char *)(param_1 + 0x1ea) == '\0') {
    func_0x80033680(param_1,0,1);
  }
  return;
}
