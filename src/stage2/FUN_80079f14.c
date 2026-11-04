/* FUN_80079f14
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80079f14  body 0x80079f14..0x8007a0f7  size 484 B
 * body sha256 d90f069de4a91e7be26ff7286c5b2b87616d23162e7f9a0dc1b4acc6225a4c9c
 * provider record sha256 df3e06166503baf7cdbb633c98418beb0513a7af430071c2d64887d780defbbd
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80079f14(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  
  if ((*(ushort *)(param_1 + 0x1aa) & 0x400) != 0) {
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) | 0x800;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x1608) = 0;
  if ((*(ushort *)(param_1 + 0x1aa) & 0x800) != 0) {
    iVar3 = *(int *)(param_1 + 0x234);
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xf7ff;
    *(undefined4 *)(iVar3 + 0x10d0) = *(undefined4 *)(iVar3 + 0x16b0);
    *(undefined4 *)(iVar3 + 0x10d4) = *(undefined4 *)(iVar3 + 0x16b4);
    *(undefined4 *)(iVar3 + 0x10d8) = *(undefined4 *)(iVar3 + 0x16b8);
    *(undefined4 *)(iVar3 + 0x10dc) = *(undefined4 *)(iVar3 + 0x16bc);
    *(undefined2 *)(iVar3 + 0x10ec) = *(undefined2 *)(iVar3 + 0x16cc);
    *(undefined2 *)(iVar3 + 0x10ee) = *(undefined2 *)(iVar3 + 0x16ce);
    *(undefined4 *)(iVar3 + 0x10f4) = *(undefined4 *)(iVar3 + 0x16d4);
    *(undefined4 *)(iVar3 + 0x10f0) = *(undefined4 *)(iVar3 + 0x16d0);
    *(undefined4 *)(iVar3 + 0x1028) = 1;
    *(undefined4 *)(iVar3 + 0x1608) = 0;
  }
  iVar3 = *(int *)(param_1 + 0x234);
  *(undefined4 *)(iVar3 + 0x1780) = 0;
  *(int *)(iVar3 + 0x17e4) = iVar3 + 0x38;
  *(undefined4 *)(iVar3 + 0x179c) = 0x42;
  *(int *)(iVar3 + 0x18ac) = iVar3;
  *(undefined4 *)(iVar3 + 0x17a0) = 0xfffffd72;
  *(undefined4 *)(iVar3 + 0x17a4) = 0;
  *(undefined2 *)(iVar3 + 0x17d8) = 0;
  *(undefined2 *)(iVar3 + 0x17da) = 0;
  *(undefined2 *)(iVar3 + 0x17dc) = 0;
  *(undefined2 *)(iVar3 + 0x18b0) = 0;
  *(undefined2 *)(iVar3 + 0x18b2) = 0;
  iVar2 = FUN_800837ac(&DAT_800e8cc0,0x50);
  if (iVar2 != 0) {
    *(undefined4 *)(iVar3 + 0x1780) = 1;
  }
  **(uint **)(param_1 + 0x234) = **(uint **)(param_1 + 0x234) | 0x4000;
  *(code **)(param_1 + 0x2a0) = FUN_800805d8;
  *(undefined1 **)(param_1 + 0x2a4) = &LAB_800805f4;
  if ((*(ushort *)(param_1 + 0x1aa) & 0x80) == 0) {
    DAT_800df934 = FUN_80035c08(param_1,DAT_800df934);
  }
  *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) | 0x80;
  if ((DAT_800e110c & 0x10000000) != 0) {
    *(undefined4 **)(param_1 + 0x254) = &DAT_800e1130;
    *(undefined1 *)(param_1 + 4) = 1;
    *(undefined1 *)(param_1 + 0x25c) = 0;
    *(undefined1 *)(param_1 + 5) = 0;
    uVar1 = DAT_800e9010;
    *(undefined2 *)(param_1 + 0x1fe) = 200;
    *(undefined2 *)(param_1 + 0x1f2) = uVar1;
  }
  *(undefined2 *)(param_1 + 0x2b8) = 0;
  *(undefined2 *)(param_1 + 0x2c0) = 0;
  *(undefined2 *)(param_1 + 700) = 0;
  *(undefined1 *)(param_1 + 0x2bf) = 0;
  *(undefined1 *)(param_1 + 0x2c6) = 0;
  *(undefined1 *)(param_1 + 0x1ed) = 0;
  return;
}
