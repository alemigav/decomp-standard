/* FUN_8008d370
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008d370  body 0x8008d370..0x8008d633  size 708 B
 * body sha256 2b11db2f10238f29fbf9169aba871fb476e5e2e33a9cd549cc063f619c2fcc9a
 * provider record sha256 8c8c174b17e0d87c74141054b44c3c91372d4b71afe1a34b983574f4b696c535
 * callees 16 direct (16 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008d370(void)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_8012bf98 = 1;
  DAT_8012bf99 = 3;
  DAT_8012bfbe = 0;
  DAT_8012bfbf = 0;
  if ((int)DAT_800e110c < 0) {
    if ((DAT_800e110c & 0x4000000) != 0) {
      DAT_80130330 = 2;
      iVar1 = FUN_800837ac(&DAT_800e8ce0,0);
      if (iVar1 != 0) {
        DAT_80130330 = 4;
      }
      iVar1 = FUN_800837ac(&DAT_800e8d98,0x40);
      if (iVar1 != 0) {
        DAT_80130330 = 6;
      }
      iVar1 = FUN_800837ac(&DAT_800e8d98,0x4f);
      if (iVar1 != 0) {
        DAT_80130330 = 9;
      }
      iVar1 = FUN_800837ac(&DAT_800e8d68,0x2b);
      if (iVar1 != 0) {
        DAT_80130330 = 10;
      }
      iVar1 = FUN_800837ac(&DAT_800e8cc0,0x43);
      if (iVar1 != 0) {
        DAT_80130330 = 0xe;
      }
    }
  }
  else if ((DAT_800e110c & 0x4000000) != 0) {
    DAT_8013032c = 2;
    iVar1 = FUN_800837ac(&DAT_800e8ce0,0xf);
    if (iVar1 != 0) {
      DAT_8013032c = 3;
    }
    iVar1 = FUN_800837ac(&DAT_800e8d98,0x40);
    if (iVar1 != 0) {
      DAT_8013032c = 5;
    }
    iVar1 = FUN_800837ac(&DAT_800e8d98,0x3c);
    if (iVar1 != 0) {
      DAT_8013032c = 6;
    }
    iVar1 = FUN_800837ac(&DAT_800e8d98,0x4f);
    if (iVar1 != 0) {
      DAT_8013032c = 8;
    }
    iVar1 = FUN_800837ac(&DAT_800e8d98,0x5a);
    if (iVar1 != 0) {
      DAT_8013032c = 9;
    }
    iVar1 = FUN_800837ac(&DAT_800e8d98,0x69);
    if (iVar1 != 0) {
      DAT_8013032c = 0xb;
    }
    iVar1 = FUN_800837ac(&DAT_800e8d68,0x2b);
    if (iVar1 != 0) {
      DAT_8013032c = 0xc;
    }
    iVar1 = FUN_800837ac(&DAT_800e8cc0,0x24);
    if (iVar1 != 0) {
      DAT_8013032c = 0xe;
    }
  }
  FUN_800274f8(0x200,0xffffe800,7,1);
  do {
    FUN_8004cd88(1);
    FUN_80043620();
    FUN_80096d90();
    FUN_800978a4();
    FUN_80097c4c();
    uVar2 = FUN_8008c3a0();
    FUN_800981d8(uVar2);
    FUN_800969a4();
    FUN_80097174();
    FUN_8008c25c(0x10,0xaf,2,(&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4]);
    FUN_80095c34();
    FUN_800962fc((&DAT_800e8eca)[(uint)DAT_8012bfa4 * 4]);
    iVar1 = FUN_8002767c(0);
  } while (iVar1 == 0);
  FUN_8006c070(1);
  return;
}
