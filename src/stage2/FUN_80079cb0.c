/* FUN_80079cb0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80079cb0  body 0x80079cb0..0x80079e9b  size 492 B
 * body sha256 5cec56d2ac884b4dcaaa44920c3db2474261ef3129ea851b9c414998e7edf7f1
 * provider record sha256 4613b2caf7cd0abb2c666efbe7956afa37ee446288cc6edb05af1153322bb003
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80079cb0(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(*(int *)(param_1 + 0x234) + 0x1608) = 0;
  if ((*(ushort *)(param_1 + 0x1aa) & 0x800) != 0) {
    iVar1 = *(int *)(param_1 + 0x234);
    *(undefined4 *)(iVar1 + 0x10d0) = *(undefined4 *)(iVar1 + 0x16b0);
    *(undefined4 *)(iVar1 + 0x10d4) = *(undefined4 *)(iVar1 + 0x16b4);
    *(undefined4 *)(iVar1 + 0x10d8) = *(undefined4 *)(iVar1 + 0x16b8);
    *(undefined4 *)(iVar1 + 0x10dc) = *(undefined4 *)(iVar1 + 0x16bc);
    *(undefined2 *)(iVar1 + 0x10ec) = *(undefined2 *)(iVar1 + 0x16cc);
    *(undefined2 *)(iVar1 + 0x10ee) = *(undefined2 *)(iVar1 + 0x16ce);
    *(undefined4 *)(iVar1 + 0x10f4) = *(undefined4 *)(iVar1 + 0x16d4);
    *(undefined4 *)(iVar1 + 0x10f0) = *(undefined4 *)(iVar1 + 0x16d0);
    *(undefined4 *)(iVar1 + 0x1608) = 0;
    *(undefined4 *)(iVar1 + 0x1028) = 1;
  }
  iVar1 = *(int *)(param_1 + 0x234);
  *(undefined4 *)(iVar1 + 0x1780) = 0;
  *(undefined4 *)(iVar1 + 0x17e4) = *(undefined4 *)(iVar1 + 100);
  *(undefined4 *)(iVar1 + 0x18ac) = *(undefined4 *)(iVar1 + 300);
  *(undefined4 *)(iVar1 + 0x179c) = *(undefined4 *)(iVar1 + 0x1c);
  *(undefined4 *)(iVar1 + 0x17a0) = *(undefined4 *)(iVar1 + 0x20);
  *(undefined2 *)(iVar1 + 0x17d8) = 0;
  *(undefined2 *)(iVar1 + 0x17da) = 0;
  *(undefined2 *)(iVar1 + 0x17dc) = 0;
  *(undefined4 *)(iVar1 + 0x17a4) = *(undefined4 *)(iVar1 + 0x24);
  FUN_80040e58(iVar1 + 0x17d8,iVar1 + 0x1788);
  FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),0);
  FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xd38,0);
  FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xeb0,0);
  FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x11a0,0);
  FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x1318,0);
  iVar1 = *(int *)(param_1 + 0x234);
  *(undefined2 *)(*(int *)(iVar1 + 0x120) + 0x10) = 0;
  FUN_80066288(param_1,iVar1);
  iVar1 = *(int *)(param_1 + 0x234);
  *(undefined2 *)(*(int *)(iVar1 + 0x18a0) + 0x10) = 0;
  FUN_80066288(param_1,iVar1 + 0x1780);
  if ((*(ushort *)(param_1 + 0x1aa) & 0x200) != 0) {
    if ((DAT_800e9012 & 8) != 0) {
      *(undefined2 *)(*(int *)(*(int *)(param_1 + 0x234) + 0x120) + 0x10) = 0x1000;
      FUN_80066288(param_1);
      iVar1 = *(int *)(param_1 + 0x234);
      *(uint *)(iVar1 + 0x1780) = *(uint *)(iVar1 + 0x1780) | 1;
      *(undefined2 *)(*(int *)(iVar1 + 0x18a0) + 0x10) = 0x1000;
      FUN_80066288(param_1,iVar1 + 0x1780);
    }
    FUN_8007ac14(param_1);
  }
  return;
}
