/* FUN_8004e774
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004e774  body 0x8004e774..0x8004eb73  size 1024 B
 * body sha256 12a8a57e83e7f9b17dc1e869eb0611460e7319c04164ddbf434faf97e2bfa27c
 * provider record sha256 96d63bcac71ef23c582534a1affcf85a76500d1c8de82325271a309fd5a1b895
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8004e774(int param_1)

{
  char cVar1;
  uint uVar2;
  short sVar3;
  undefined1 uVar4;
  int iVar5;
  undefined4 uVar6;
  uint *puVar7;
  ushort uVar8;
  short local_30 [2];
  short local_2c;
  int local_28;
  undefined4 local_24;
  int local_20;
  
  uVar8 = *(short *)(param_1 + 0x66) + 0x200U & 0xfc00;
  if (*(byte *)(param_1 + 8) < 0x10) {
    iVar5 = *(byte *)(param_1 + 8) + 0x10;
  }
  else {
    iVar5 = *(byte *)(param_1 + 8) - 0x40;
  }
  local_30[0] = *(short *)(&DAT_8010ba78 + iVar5 * 2);
  local_2c = 0;
  FUN_800837d0((int)(short)uVar8,local_30,local_30);
  local_28 = (int)local_30[0] + *(int *)(param_1 + 0x28);
  local_24 = *(int *)(param_1 + 0x2c) + -0x708;
  local_20 = (int)local_2c + *(int *)(param_1 + 0x30);
  cVar1 = *(char *)(param_1 + 8);
  if (((cVar1 == '\x0f') || (cVar1 == 'E')) || (cVar1 == 'O')) {
    uVar6 = 0x800;
  }
  else {
    uVar6 = 0x1000;
  }
  uVar2 = FUN_800667d4(&local_28,0,1 << (*(byte *)(param_1 + 0x1a2) & 0x1f),uVar6);
  if ((((uVar2 & 2) == 0) || (0x1e < *(byte *)(param_1 + 0x1a2))) ||
     ((sVar3 = FUN_80069f1c(&local_28,*(undefined2 *)(param_1 + 0x136),
                            (uint)*(byte *)(param_1 + 9) << 8,0), local_24 < sVar3 ||
      (((DAT_8011270c & 1) != 0 || (iVar5 = FUN_8004f814(&local_28,param_1), iVar5 != 0)))))) {
    if (*(byte *)(param_1 + 8) < 0x10) {
      iVar5 = *(byte *)(param_1 + 8) + 0x10;
    }
    else {
      iVar5 = *(byte *)(param_1 + 8) - 0x40;
    }
    local_30[0] = *(short *)(&DAT_8010bab8 + iVar5 * 2);
    local_2c = 0;
    FUN_800837d0((int)(short)uVar8,local_30,local_30);
    local_28 = (int)local_30[0] + *(int *)(param_1 + 0x28);
    local_20 = (int)local_2c + *(int *)(param_1 + 0x30);
    local_24 = *(undefined4 *)(param_1 + 0x2c);
    local_24 = FUN_80069f1c(&local_28,*(undefined2 *)(param_1 + 0x136),
                            (uint)*(byte *)(param_1 + 9) << 8,0);
    cVar1 = *(char *)(param_1 + 8);
    if (((cVar1 == '\x0f') || (cVar1 == 'E')) || (cVar1 == 'O')) {
      uVar6 = 0x800;
    }
    else {
      uVar6 = 0x1000;
    }
    uVar2 = FUN_800667d4(&local_28,0,1 << (*(byte *)(param_1 + 0x1a2) & 0x1f),uVar6);
    if ((local_24 <= *(int *)(param_1 + 0x2c)) || ((uVar2 & 4) == 0)) {
      return 0;
    }
    puVar7 = &DAT_800e18f8;
    if (&DAT_800e18f8 < DAT_800e85f8) {
      do {
        if ((((*puVar7 & 1) != 0) && ((*puVar7 & 2) == 0)) &&
           (puVar7 != *(uint **)(param_1 + 0x280))) {
          iVar5 = FUN_8004f774(&local_28,puVar7,*(undefined2 *)(param_1 + 0x136),1);
          if (iVar5 != 0) {
            return 0;
          }
          sVar3 = local_24._2_2_;
          local_24 = *(undefined4 *)(param_1 + 0x2c);
          iVar5 = FUN_8004f774(&local_28,puVar7,*(undefined2 *)(param_1 + 0x136),1);
          if (iVar5 != 0) {
            return 0;
          }
          local_24 = (int)sVar3;
        }
        puVar7 = puVar7 + 0xda;
      } while (puVar7 < DAT_800e85f8);
    }
    iVar5 = FUN_8004f814(&local_28,param_1);
    if (iVar5 != 0) {
      return 0;
    }
    if ((((DAT_800e110c & 0x10000000) == 0) || (uVar4 = 8, param_1 != DAT_800e13ec)) &&
       (uVar4 = 0x19, *(char *)(param_1 + 5) == '\x04')) {
      uVar4 = 0x17;
    }
    *(undefined1 *)(param_1 + 5) = uVar4;
    *(undefined1 *)(param_1 + 6) = 2;
  }
  else {
    if ((((DAT_800e110c & 0x10000000) == 0) || (uVar4 = 8, param_1 != DAT_800e13ec)) &&
       (uVar4 = 0x18, *(char *)(param_1 + 5) == '\x04')) {
      uVar4 = 0x16;
    }
    *(undefined1 *)(param_1 + 5) = uVar4;
    *(undefined1 *)(param_1 + 6) = 0;
  }
  *(undefined1 *)(param_1 + 7) = 0;
  *(undefined2 *)(param_1 + 0x2b0) = *(undefined2 *)(param_1 + 0x66);
  return 1;
}
