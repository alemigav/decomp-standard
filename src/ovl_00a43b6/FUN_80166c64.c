/* FUN_80166c64
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x80166c64  body 0x80166c64..0x80166cdf  size 124 B
 * body sha256 f67ff32494c5aba2e80dd3da1c1626981266cf3d751c19ca3978dff38100dab4
 * provider record sha256 dba181673a4105be30e4986ea6819b5644805493d1d60d7e88c54bd6f8c724b6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
ushort FUN_80166c64(int param_1)

{
  ushort uVar1;
  int iVar2;
  
  if ((*(ushort *)(param_1 + 0x2b8) & 0x40) == 0) {
    iVar2 = *(int *)(param_1 + 0x234);
    *(uint *)(iVar2 + 0x8d0) = *(uint *)(iVar2 + 0x8d0) | 0x80;
    *(undefined4 *)(iVar2 + 0xa00) = 0x40;
    *(undefined4 *)(iVar2 + 0xa04) = 0x30;
    *(uint *)(iVar2 + 0xa48) = *(uint *)(iVar2 + 0xa48) | 0x80;
    *(undefined4 *)(iVar2 + 0xb78) = 0x40;
    *(undefined4 *)(iVar2 + 0xb7c) = 0x30;
    *(uint *)(iVar2 + 0xbc0) = *(uint *)(iVar2 + 0xbc0) | 0x80;
    *(undefined4 *)(iVar2 + 0xcf0) = 0x40;
    *(undefined4 *)(iVar2 + 0xcf4) = 0x30;
    uVar1 = *(ushort *)(param_1 + 0x2b8) | 0x40;
    *(ushort *)(param_1 + 0x2b8) = uVar1;
    return uVar1;
  }
  return 0;
}
