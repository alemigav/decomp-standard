/* FUN_8017d61c
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017d61c  body 0x8017d61c..0x8017d743  size 296 B
 * body sha256 cc9155720fb769954cca26af5ad3a4f70fee203fe8e9b301335bf5c2d2986446
 * provider record sha256 f3b82baf5762c6e9f97ebcb53bf097c80ab88d05e632803f5af45f7256714e5b
 * callees 12 direct (12 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017d61c(void)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_8017d214();
  do {
    iVar1 = FUN_8017bbb0(0x20);
    if (iVar1 == 0x1b5) {
      FUN_8017bd8c();
      uVar2 = FUN_8017bec8(4);
      switch(uVar2) {
      case 1:
        FUN_8017d744();
        break;
      case 2:
        FUN_8017d81c();
        break;
      case 3:
        FUN_8017d880();
        break;
      case 5:
        FUN_8017d9e4();
        break;
      case 7:
        FUN_8017da9c();
        break;
      case 8:
        FUN_8017db54();
        break;
      case 9:
        FUN_8017dca4();
        break;
      case 10:
        FUN_8017dd70();
      }
    }
    else {
      if (iVar1 != 0x1b2) {
        return;
      }
      FUN_8017bd8c();
    }
    FUN_8017d214();
  } while( true );
}
