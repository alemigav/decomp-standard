/* FUN_800ae1a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ae1a0  body 0x800ae1a0..0x800ae2ff  size 352 B
 * body sha256 038546d89818a55205f4196853f0062f104f98eeaa81ef9443e752cb55a7d319
 * provider record sha256 cdb1f74e9b186a9d2935b1396f174ec1e1ec5aa759e985c6134f6d9f8deb6927
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800ae1a0(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  
  FUN_800b1b08();
  if (*(int *)(param_1 + 0x60) != -1) {
    if (*(uint *)(param_1 + 0x14) == 0xffffffff) {
      if (*(int *)(param_1 + 0x10) == -1) {
        puVar1 = *(undefined4 **)(param_1 + 0x18);
        if ((undefined4 *)puVar1[1] == (undefined4 *)0x0) {
          _DAT_80158430 = *puVar1;
        }
        else {
          *(undefined4 *)puVar1[1] = *puVar1;
        }
        piVar2 = *(int **)(param_1 + 0x18);
        if (*piVar2 != 0) {
          *(int *)(*piVar2 + 4) = piVar2[1];
          piVar2 = *(int **)(param_1 + 0x18);
        }
        *piVar2 = _DAT_80158434;
        if (_DAT_80158434 != 0) {
          *(undefined4 *)(_DAT_80158434 + 4) = *(undefined4 *)(param_1 + 0x18);
        }
        *(undefined4 *)(*(int *)(param_1 + 0x18) + 4) = 0;
        _DAT_80158434 = *(int *)(param_1 + 0x18);
      }
      else {
        *(int *)(*(int *)(param_1 + 0x18) + 0xc) = *(int *)(param_1 + 0x10);
        *(undefined4 *)((uint)*(byte *)(param_1 + 0x13) * 0x1a0 + -0x7febbba4) = 0xffffffff;
        *(undefined4 *)((uint)*(byte *)(param_1 + 0x13) * 0x1a0 + -0x7febbba0) =
             *(undefined4 *)(param_1 + 0x18);
      }
    }
    else {
      *(undefined4 *)((*(uint *)(param_1 + 0x14) & 0xff) * 0x1a0 + -0x7febbba8) =
           *(undefined4 *)(param_1 + 0x10);
      if (*(uint *)(param_1 + 0x10) != 0xffffffff) {
        *(undefined4 *)((*(uint *)(param_1 + 0x10) & 0xff) * 0x1a0 + -0x7febbba4) =
             *(undefined4 *)(param_1 + 0x14);
      }
    }
  }
  return;
}
