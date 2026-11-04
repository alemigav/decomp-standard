/* FUN_80162f98
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80162f98  body 0x80162f98..0x80163093  size 252 B
 * body sha256 20b011120343b834897a38e7b134389dc0c374e7063ab9c4277e69a82d8b3ee3
 * provider record sha256 8089362a2f55b0ce8584176eee8be064aeaf58425557c2e8c9e9fbf8bf890cd0
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162f98(int param_1)

{
  byte bVar2;
  uint uVar1;
  undefined2 uVar3;
  undefined1 *puVar4;
  
  if (*(char *)(param_1 + 0x2b4) == '\0') {
    puVar4 = &DAT_800e1130;
  }
  else {
    puVar4 = _DAT_800e13ec;
  }
  uVar3 = 0xfce0;
  bVar2 = *(byte *)(param_1 + 0x2cd) ^ 1;
  *(byte *)(param_1 + 0x2cd) = bVar2;
  if (bVar2 == 0) {
    uVar3 = 800;
  }
  *(undefined2 *)(param_1 + 0x130) = uVar3;
  *(undefined1 *)(param_1 + 0x2ce) = 0x3c;
  *(undefined1 *)(param_1 + 5) = 1;
  *(undefined2 *)(param_1 + 6) = 0;
  *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
  FUN_80166a04(param_1);
  if ((*(uint *)(puVar4 + 4) & 0xffff0000) == 0x1020000) {
    uVar1 = func_0x80033604();
    if ((0xbd0 >> (uVar1 & 0xf) & 1U) != 0) {
      *(undefined1 *)(param_1 + 5) = 5;
      *(undefined1 *)(param_1 + 0x2da) = 1;
    }
    *(undefined1 *)(param_1 + 0x2be) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0x2be) = 0;
  }
  *(undefined1 *)(param_1 + 700) = 0;
  *(undefined1 *)(param_1 + 0x2bd) = 0;
  return;
}
