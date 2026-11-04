/* FUN_8007db74
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007db74  body 0x8007db74..0x8007dc7b  size 264 B
 * body sha256 6c633d50a5fd5b6e6716470104981058a980da3912116622924c18a34fd754fa
 * provider record sha256 c806d09094e20075af58347c4f4c766a20fb05475a53650cb03eefd8bda0bc37
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007db74(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  
  bVar1 = *(byte *)(param_1 + 7);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined2 *)(param_1 + 6) = 0x100;
        *(undefined1 *)(param_1 + 0x1ea) = 7;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0x9000700;
    *(undefined1 *)(param_1 + 0x207) = 6;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 0x12;
    *(undefined1 *)(param_1 + 7) = 1;
    *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) | 0x4000;
    if ((*(short *)(param_1 + 0x1a8) != 0) &&
       (*(short *)(param_1 + 0x1a8) < *(short *)(param_1 + 0x25e))) {
      FUN_8005c3e8(param_1);
    }
  }
  iVar2 = *(int *)(param_1 + 0x250);
  if (iVar2 != param_1) {
    FUN_80032dbc(param_1,*(undefined4 *)(iVar2 + 0x28),*(undefined4 *)(iVar2 + 0x30),0xd8);
  }
  cVar3 = FUN_80089d54(param_1,param_2,param_3,0x200);
  *(char *)(param_1 + 7) = *(char *)(param_1 + 7) + cVar3;
  return;
}
