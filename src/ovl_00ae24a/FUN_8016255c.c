/* FUN_8016255c
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x8016255c  body 0x8016255c..0x801628c7  size 876 B
 * body sha256 0035e18c705d4e518bb35e9f0fb2786d1eab887dbc03202eee997eb983c7f9a0
 * provider record sha256 89101f2a14ef5f866abb5d2984dc07d2cf8ab4a87994468ffb2cb89626f2c862
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016255c(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  short sVar2;
  ushort uVar5;
  int iVar3;
  uint uVar4;
  byte bVar6;
  char cVar7;
  uint uVar8;
  undefined1 local_20 [8];
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x1f00;
    *(undefined1 *)(param_1 + 6) = 1;
    uVar5 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar5 & 0x1f) + 0x78;
    *(undefined1 *)(param_1 + 0x207) = 0;
    if ((*(int *)(param_1 + 0x28) < 8000) || (11000 < *(uint *)(param_1 + 0x28c))) {
      iVar3 = 4;
      uVar4 = 0;
      bVar6 = 0;
      do {
        iVar3 = iVar3 + -1;
        if ((((int)(uint)*(byte *)(param_1 + 0x2c4) >> (uVar4 & 0x1f) & 1U) == 0) &&
           (((int)(uint)*(byte *)(param_1 + 0x2c4) >> (uVar4 + 4 & 0x1f) & 1U) == 0)) {
          local_20[bVar6] = (char)uVar4;
          bVar6 = bVar6 + 1;
        }
        uVar4 = uVar4 + 1;
      } while (iVar3 != 0);
      if (bVar6 == 4) goto LAB_801628a4;
      *(undefined1 *)(param_1 + 0x207) = 1;
      *(undefined2 *)(param_1 + 500) = 10;
    }
    uVar4 = func_0x80033604();
    uVar8 = func_0x80033604();
    *(byte *)(param_1 + 0x206) = (byte)((int)(uVar4 & 0xff) >> (uVar8 & 3)) & 7;
    if (*(uint *)(param_1 + 0x28c) < 7000) {
      *(undefined1 *)(param_1 + 0x206) = 0;
    }
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  iVar3 = func_0x80089d54(param_1,param_2,param_3,0x80);
  if ((iVar3 != 0) && (uVar4 = func_0x80033604(), (uVar4 & 3) != 0)) {
    func_0x80077d18(9,param_1);
  }
  if (((*(ushort *)(param_1 + 500) & 0xf) == 0) &&
     (iVar3 = 4, (*(byte *)(param_1 + 0x207) & 1) == 0)) {
    uVar8 = 0;
    uVar4 = 0;
    do {
      iVar3 = iVar3 + -1;
      if ((((int)(uint)*(byte *)(param_1 + 0x2c4) >> (uVar8 & 0x1f) & 1U) == 0) &&
         (((int)(uint)*(byte *)(param_1 + 0x2c4) >> (uVar8 + 4 & 0x1f) & 1U) == 0)) {
        local_20[uVar4 & 0xff] = (char)uVar8;
        uVar4 = uVar4 + 1;
      }
      uVar8 = uVar8 + 1;
    } while (iVar3 != 0);
    uVar4 = uVar4 & 0xff;
    if (uVar4 != 0) {
      if (*(uint *)(param_1 + 0x28c) < 7000) {
        *(undefined1 *)(param_1 + 0x206) = 0;
      }
      uVar8 = func_0x80033604();
      if (uVar4 == 0) {
        trap(0x1c00);
      }
      uVar1 = local_20[(uVar8 & 0xff) % uVar4];
      uVar4 = func_0x80033604();
      uVar8 = func_0x80033604();
      FUN_801667c0(uVar1,*(undefined4 *)
                          (&DAT_80166fb8 +
                          ((int)(uVar4 & 0xff) >> (uVar8 & 3) & 1U) * 4 +
                          *(char *)(param_1 + 0x206) * 8));
    }
  }
  sVar2 = *(short *)(param_1 + 500);
  if ((*(short *)(param_1 + 500) != 0) && (*(short *)(param_1 + 500) = sVar2 + -1, sVar2 != 1)) {
    return;
  }
  iVar3 = 4;
  uVar4 = 0;
  cVar7 = '\0';
  *(byte *)(param_1 + 0x207) = *(byte *)(param_1 + 0x207) | 1;
  do {
    if ((((int)(uint)*(byte *)(param_1 + 0x2c4) >> (uVar4 & 0x1f) & 1U) == 0) &&
       (((int)(uint)*(byte *)(param_1 + 0x2c4) >> (uVar4 + 4 & 0x1f) & 1U) != 0)) {
      cVar7 = cVar7 + '\x01';
    }
    iVar3 = iVar3 + -1;
    uVar4 = uVar4 + 1;
  } while (iVar3 != 0);
  if (cVar7 != '\0') {
    return;
  }
  *(undefined4 *)(param_1 + 4) = 0x1030000;
  uVar4 = func_0x80033604();
  if (((uVar4 & 3) != 0) && (*(int *)(param_1 + 0x28) < 10000)) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  if (10000 < *(uint *)(param_1 + 0x28c)) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  if ((9000 < *(int *)(param_1 + 0x28)) && (uVar4 = func_0x80033604(), (uVar4 & 1) == 0)) {
    *(undefined4 *)(param_1 + 4) = 0x1030000;
  }
  if (6999 < *(int *)(param_1 + 0x28)) {
    return;
  }
  uVar4 = func_0x80033604();
  if ((uVar4 & 1) != 0) {
    return;
  }
LAB_801628a4:
  *(undefined4 *)(param_1 + 4) = 0x1010000;
  return;
}
