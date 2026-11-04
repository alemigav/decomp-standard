/* FUN_8000a0f0
 * image   boot (boot), base 0x80000480
 * address 0x8000a0f0  body 0x8000a0f0..0x8000a2cf  size 480 B
 * body sha256 5f4e5b3e187437a01e667b4c066bdc02ee70e988446138616955b5233b5a19d0
 * provider record sha256 87a008f778836b41ffb69b04768b2027016998eb1e3504623290b8756c9fb486
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8000a0f0(int param_1)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  ushort *puVar7;
  ushort local_58 [14];
  ushort local_3c;
  short local_3a;
  ushort local_38 [12];
  ushort local_20;
  ushort local_18;
  short local_16;
  
  if (*(char *)(param_1 + 0x65) != '\0') {
    *(undefined1 *)(param_1 + 0x65) = 0;
    uVar3 = FUN_8000a66c();
    if (uVar3 != 0) {
      return uVar3;
    }
  }
  uVar3 = FUN_800087a0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),1,local_58);
  puVar6 = local_58;
  if (uVar3 != 0) {
    return uVar3;
  }
  local_16 = 0;
  local_18 = 0;
  do {
    uVar2 = *puVar6;
    puVar6 = puVar6 + 1;
    local_18 = local_18 + uVar2;
    local_16 = local_16 + ~uVar2;
  } while (puVar6 < &local_3c);
  puVar6 = local_58;
  if ((local_3c != local_18) || (local_3a != local_16)) {
    uVar3 = FUN_80009f8c(param_1,puVar6);
    if (uVar3 == 10) {
      uVar3 = FUN_80009cac(param_1,puVar6,local_38);
      puVar6 = local_38;
    }
    if (uVar3 != 0) {
      return uVar3;
    }
  }
  puVar7 = puVar6;
  if ((puVar6[0xc] & 1) == 0) {
    puVar7 = local_38;
    uVar3 = FUN_80009cac(param_1,puVar6,puVar7);
    if (uVar3 != 0) {
      return uVar3;
    }
    if ((local_20 & 1) == 0) {
      return 0xb;
    }
  }
  iVar5 = 0;
  puVar6 = puVar7;
  do {
    iVar4 = param_1 + iVar5;
    iVar5 = iVar5 + 1;
    *(undefined1 *)(iVar4 + 0xc) = *(undefined1 *)puVar6;
    puVar6 = (ushort *)((int)puVar6 + 1);
  } while (iVar5 < 0x20);
  *(uint *)(param_1 + 0x4c) = (uint)*(byte *)((int)puVar7 + 0x1b);
  bVar1 = *(byte *)(puVar7 + 0xd);
  *(undefined4 *)(param_1 + 0x50) = 0x10;
  *(undefined4 *)(param_1 + 0x54) = 8;
  *(byte *)(param_1 + 100) = bVar1;
  *(uint *)(param_1 + 0x60) = (uint)bVar1 * 2 + 3;
  iVar5 = (*(byte *)(param_1 + 100) + 1) * 8;
  *(int *)(param_1 + 0x58) = iVar5;
  *(uint *)(param_1 + 0x5c) = iVar5 + (uint)*(byte *)(param_1 + 100) * 8;
  uVar3 = FUN_800087a0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),7,param_1 + 0x2c);
  return uVar3 & -(uint)(uVar3 != 0);
}
