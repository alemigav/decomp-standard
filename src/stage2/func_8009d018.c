/* func_8009d018
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009d018  body 0x8009d018..0x8009d053  size 60 B
 * body sha256 5a8fe9742d4b602d09dac941b1601d1b17731ebc7d1500f29ca2a4c717fbaaf6
 * provider record sha256 3f8bd233d421ffb72484103c3ac17c144c41a42ff20733b54e68619502b343a8
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void func_8009d018(void)

{
  int iVar1;
  
  switch(DAT_8013272e) {
  case 0:
    FUN_8009e93c(3,0,0xffff,0);
    FUN_800777d8(0x1006b00);
    DAT_80012888 = 0x6b;
    DAT_8013273a = 0;
    DAT_8013272e = 1;
    DAT_8013272b = 3;
    goto LAB_8009d858;
  case 1:
    if (DAT_8013273a == 0xf0) {
      FUN_80025f78(1,2,&DAT_80132644);
      FUN_80025f78(0,2,&DAT_80132628);
      FUN_8009ce40();
    }
    if (DAT_8013273a == 0x1a4) {
      func_0x80004a6c(1,1);
    }
    if (DAT_8013273a == 0x1ae) {
      DAT_80132740 = 3;
      FUN_8009e8d4(7,1);
    }
    if (DAT_8013273a == 0x319) {
      DAT_80132740 = 3;
      FUN_8009e8d4(0xb,0);
    }
    if (DAT_8013273a != 0x337) goto LAB_8009d858;
    DAT_80132658 = DAT_800c52d8 + 62000;
    FUN_80025f78(0,2);
    FUN_8009ced8();
    DAT_8013272b = 0;
    FUN_8009ce40();
    DAT_80132728 = 8;
    DAT_80132740 = 0x3c;
    FUN_8009e8d4(0x17,0);
    DAT_8013272e = 2;
    break;
  case 2:
    if ((DAT_8013273a & 0xf) == 0) {
      DAT_80132674 = DAT_80132674 + 0x140;
      FUN_80025f78(0,2);
    }
    if (DAT_8013273a == 0x40) {
      func_0x80004a6c(1,2);
    }
    if (DAT_8013273a == 0x4a) {
      DAT_80132740 = 0xc0;
      FUN_8009e8d4(7,0);
    }
    if (DAT_8013273a == 0x15d) {
      DAT_80132740 = 0xc0;
      FUN_8009e8d4(0xb,0);
    }
    if (DAT_8013273a == 0x167) {
      DAT_80132740 = 0x300;
      FUN_8009e8d4(7,0);
    }
    if (DAT_8013273a == 0x36b) {
      DAT_80132740 = 0x300;
      FUN_8009e8d4(0xb,0);
      FUN_8009ced8();
    }
    if (DAT_8013273a != 0x389) goto LAB_8009d858;
    DAT_80132740 = 0x3c;
    FUN_8009e8d4(0x1b,0);
    DAT_80132740 = 0x400;
    FUN_8009e8d4(0x47,0);
    DAT_8013272e = 3;
    goto LAB_8009d434;
  case 3:
    if (DAT_8013273a == 0x5e) {
      FUN_80025f78(1,2,&DAT_8013267c);
      DAT_8013272b = 3;
      FUN_8009ce40();
      DAT_80132740 = 0x7800;
      FUN_8009e8d4(7,0);
      func_0x80004a6c(1,3);
    }
    if (DAT_8013273a == 0x68) {
      DAT_80132740 = 0x18000;
      FUN_8009e8d4(7,0);
    }
    if (DAT_8013273a == 0xcc) {
      DAT_80132740 = 0x400;
      FUN_8009e8d4(0x4b,0);
    }
    if (DAT_8013273a == 0x17d) {
      DAT_80132740 = 0x18000;
      FUN_8009e8d4(0xb,0);
    }
    if (DAT_8013273a != 0x19b) goto LAB_8009d858;
    FUN_80025f78(0,2,&DAT_80132698);
    DAT_8013272b = 3;
    DAT_80132728 = 0;
    FUN_8009ced8();
    DAT_8013272b = 0;
    FUN_8009ce40();
    DAT_80132740 = 0x7800;
    FUN_8009e8d4(0xb,0);
    DAT_8013272e = 4;
LAB_8009d434:
    DAT_8013273a = 0;
    goto LAB_8009d858;
  case 4:
    if (DAT_8013273a == 0x5e) {
      DAT_80132740 = 0;
      FUN_8009e8d4(0,1);
      func_0x80004a6c(1,4);
    }
    if (DAT_8013273a == 0x68) {
      DAT_80132740 = 0x60000;
      FUN_8009e8d4(7,0);
    }
    if (DAT_8013273a == 0x226) {
      DAT_80132708 = 0;
      DAT_8013270c = 0;
      DAT_80132710 = 0;
      DAT_80132714 = 0;
      DAT_80132718 = 0;
      DAT_8013271c = 0;
      DAT_80132720 = 0;
      DAT_80132728 = DAT_80132728 ^ 2;
      FUN_8009ced8();
      DAT_80132740 = 0x60000;
      FUN_8009e8d4(0xb,0);
    }
    if (DAT_8013273a != 0x244) goto LAB_8009d858;
    DAT_80132728 = 8;
    DAT_80132740 = 0x80000;
    FUN_8009e8d4(0x27,0);
    DAT_8013272e = 5;
    break;
  case 5:
    if (DAT_8013273a == 0x60) {
      FUN_80025f78(1,2,&DAT_801326b4);
      DAT_8013272b = 3;
      DAT_80132728 = 0;
      FUN_8009ce40();
      DAT_80132740 = 0xf00000;
      FUN_8009e8d4(7,0);
      func_0x80004a6c(1,5);
    }
    if (DAT_8013273a == 0x6a) {
      DAT_80132740 = 0x3000000;
      FUN_8009e8d4(7,0);
    }
    if (DAT_8013273a == 0xc9) {
      DAT_80132740 = 0x3000000;
      FUN_8009e8d4(0xb,0);
    }
    if (DAT_8013273a == 0xd3) {
      DAT_80132740 = 0xc000000;
      FUN_8009e8d4(7,0);
    }
    if (DAT_8013273a == 0x105) {
      DAT_80132740 = 0x80000;
      FUN_8009e8d4(0x2b,0);
    }
    if (DAT_8013273a == 0x145) {
      DAT_80132740 = 0xc000000;
      FUN_8009e8d4(0xb,0);
    }
    if (DAT_8013273a == 0x1bd) {
      FUN_80077430(0x5a,0x18);
      DAT_80132728 = 8;
      DAT_80132729 = 0;
      DAT_8013272c = 2;
      FUN_8009ced8();
    }
    if ((DAT_8013273a < 0x1be) || (iVar1 = FUN_8002767c(DAT_8013272b), iVar1 == 0))
    goto LAB_8009d858;
    DAT_80132729 = 1;
    DAT_80132740 = 0;
    FUN_8009e8d4(0);
    DAT_8013272e = 6;
    break;
  case 6:
    if ((DAT_8013273a != 100) || (DAT_80119e70 != '\0')) goto LAB_8009d858;
    DAT_800e90f8 = 1;
    DAT_800e110c = DAT_800e110c & 0xffffffef;
    FUN_8006c070(0);
    FUN_8009f320(3);
    DAT_8013272e = 7;
    break;
  case 7:
    if ((DAT_800e10ec & 0x200) != 0) goto LAB_8009d858;
    FUN_8006c070(1);
    DAT_8013272e = 8;
    goto LAB_8009d818;
  case 8:
    if (DAT_8013273a != 1) goto LAB_8009d858;
    FUN_8006c070(0);
    FUN_8009f320(0xf);
    DAT_8013272e = 9;
    break;
  case 9:
    if ((DAT_800e10ec & 0x200) != 0) goto LAB_8009d858;
    FUN_8006c070(1);
    DAT_8013272e = 10;
LAB_8009d818:
    DAT_8013273a = 0;
    goto LAB_8009d858;
  case 10:
    if (DAT_8013273a == 10) {
      DAT_8013272a = 3;
      DAT_8013273c = 4;
    }
  default:
    goto LAB_8009d858;
  }
  DAT_8013273a = 0;
LAB_8009d858:
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
