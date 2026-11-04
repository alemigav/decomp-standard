/* FUN_8017b9ec
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017b9ec  body 0x8017b9ec..0x8017bbaf  size 452 B
 * body sha256 54f98704867d3b50e3ef9dbcf7bc6e8c2cb760965c66b46f362e807d9f279b05
 * provider record sha256 facfaed1b6c80ec25c1885db9b9437815c492cacd9c4d2bebfbb1bc7e5396d30
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017b9ec(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  do {
    while( true ) {
      uVar2 = FUN_8017b9bc();
      if (uVar2 != 0x1ba) break;
      DAT_80186c94[2] = DAT_80186c94[2] + 8;
    }
    if (uVar2 < 0x1bb) {
      if (uVar2 == 0x1b9) {
        iVar3 = 0;
        do {
          *(undefined1 *)(*DAT_80186c94 + iVar3) = 0;
          *(undefined1 *)(*DAT_80186c94 + iVar3 + 1) = 0;
          *(undefined1 *)(*DAT_80186c94 + iVar3 + 2) = 1;
          iVar4 = iVar3 + 3;
          iVar3 = iVar3 + 4;
          *(undefined1 *)(*DAT_80186c94 + iVar4) = 0xb7;
          piVar1 = DAT_80186c94;
        } while (iVar3 < 0x800);
        iVar3 = *DAT_80186c94;
        DAT_80186c94[2] = iVar3;
        piVar1[6] = iVar3 + 0x800;
        return;
      }
    }
    else if (uVar2 == 0x1e0) {
      iVar3 = FUN_8017b98c();
      DAT_80186c94[6] = DAT_80186c94[2] + iVar3;
      do {
        uVar2 = FUN_8017b8f4();
      } while (uVar2 == 0xff);
      if (0x3f < uVar2) {
        DAT_80186c94[2] = DAT_80186c94[2] + 1;
        uVar2 = FUN_8017b8f4();
      }
      if (uVar2 < 0x30) {
        if (0x1f < uVar2) {
          DAT_80186c94[2] = DAT_80186c94[2] + 4;
        }
      }
      else {
        DAT_80186c94[2] = DAT_80186c94[2] + 9;
      }
      return;
    }
    if (0x1ba < uVar2) {
      iVar3 = FUN_8017b98c();
      DAT_80186c94[2] = DAT_80186c94[2] + iVar3;
    }
  } while( true );
}
