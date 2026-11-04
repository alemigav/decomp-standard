/* FUN_80162af8
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80162af8  body 0x80162af8..0x80162be3  size 236 B
 * body sha256 9420081e611bfb3eb11287dad650b1f3a5784c4c08928bf2178bcb003e55bea6
 * provider record sha256 132027484e16d88213484c25be6741651c1864e7a9607f10800631d5e580dc27
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162af8(uint *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (*(char *)((int)param_1 + 7) == '\0') {
    *(undefined1 *)((int)param_1 + 7) = 1;
  }
  else {
    *(ushort *)((int)param_1 + 0x1aa) = (ushort)*(byte *)((int)param_1 + 0x1ab);
    *param_1 = *param_1 & 0xfffff7ff;
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) & 0xfe;
    puVar1 = &DAT_80167dbc;
    uVar4 = 0;
    do {
      uVar3 = uVar4 + 1;
      FUN_80167bd8(param_1,*puVar1,0,0);
      puVar1 = &DAT_80167dbd + uVar4;
      uVar4 = uVar3;
    } while (uVar3 < 8);
    uVar4 = 0x14;
    iVar2 = 0x1d60;
    do {
      uVar4 = uVar4 + 1;
      *(uint *)(param_1[0x8d] + iVar2) = *(uint *)(param_1[0x8d] + iVar2) & 0xfffffbff;
      iVar2 = iVar2 + 0x178;
    } while (uVar4 < 0x17);
    *(undefined1 *)(param_1 + 0xb1) = 0;
    *(undefined1 *)((int)param_1 + 0x2c5) = 1;
    *(undefined1 *)((int)param_1 + 5) = 1;
    *(undefined2 *)((int)param_1 + 6) = 0;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
  }
  return;
}
