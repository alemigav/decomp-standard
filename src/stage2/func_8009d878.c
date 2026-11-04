/* func_8009d878
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009d878  body 0x8009d878..0x8009d8af  size 56 B
 * body sha256 d5af22f9a79ff8ac7905f936629e33fc0f4586c160165c1e5a8e2c87114d6323
 * provider record sha256 020ea8e7262feffff3b6fcde1c26c69e74f370352d8199d0fee74e492b377f54
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void func_8009d878(void)

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
    goto LAB_8009de34;
  case 1:
    if (DAT_8013273a == 0xf0) {
      func_0x80004a6c(1,6);
    }
    if (DAT_8013273a == 0xfa) {
      DAT_80132740 = 3;
      FUN_8009e8d4(7,0);
    }
    if (DAT_8013273a != 0x20b) goto LAB_8009de34;
    DAT_80132740 = 3;
    FUN_8009e8d4(0xb,0);
    DAT_8013272e = 2;
    break;
  case 2:
    if (DAT_8013273a == 1) {
      func_0x80004a6c(1,7);
    }
    if (DAT_8013273a == 0xb) {
      DAT_80132740 = 0xc;
      FUN_8009e8d4(7,0);
    }
    if (DAT_8013273a == 0xbe) {
      func_0x80004a6c(1,8);
    }
    if (DAT_8013273a != 0x184) goto LAB_8009de34;
    DAT_80132740 = 0xc;
    FUN_8009e8d4(0xb,0);
    FUN_80025f78(0,2,&DAT_80132628);
    FUN_80025f78(1,2,&DAT_80132644);
    FUN_8009ce40();
    DAT_8013272e = 3;
    break;
  case 3:
    if (DAT_8013273a == 0x80) {
      func_0x80004a6c(1,9);
    }
    if (DAT_8013273a == 0x8a) {
      DAT_80132740 = 0x30;
      FUN_8009e8d4(7,0);
    }
    if (DAT_8013273a == 0x150) {
      DAT_80132740 = 0x30;
      FUN_8009e8d4(0xb,0);
    }
    if (DAT_8013273a != 0x18c) goto LAB_8009de34;
    FUN_8009ced8();
    DAT_80132728 = 8;
    DAT_8013272e = 4;
    break;
  case 4:
    if (DAT_8013273a == 0x3c) {
      func_0x80004a6c(1,10);
    }
    if (DAT_8013273a == 0x46) {
      DAT_80132740 = 0xc0;
      FUN_8009e8d4(7,0);
    }
    if (DAT_8013273a != 0x112) goto LAB_8009de34;
    DAT_80132740 = 0xc0;
    FUN_8009e8d4(0xb,0);
    DAT_8013272e = 5;
    break;
  case 5:
    if (DAT_8013273a == 1) {
      func_0x80004a6c(1,0xb);
    }
    if (DAT_8013273a == 0xb) {
      DAT_80132740 = 0x300;
      FUN_8009e8d4(7,0);
    }
    if (DAT_8013273a != 0xfd) goto LAB_8009de34;
    DAT_80132740 = 0x300;
    FUN_8009e8d4(0xb,0);
    FUN_80025f78(1,2,&DAT_80132660);
    FUN_8009ce40();
    DAT_8013272e = 6;
    break;
  case 6:
    if (DAT_8013273a == 0x80) {
      func_0x80004a6c(1,0xc);
    }
    if (DAT_8013273a == 0x8a) {
      DAT_80132740 = 0xc00;
      FUN_8009e8d4(7,0);
    }
    if (DAT_8013273a == 0x133) {
      DAT_80132740 = 0xc00;
      FUN_8009e8d4(0xb,0);
    }
    if (DAT_8013273a == 0x205) {
      FUN_80077430(0x5a,0x18);
      DAT_80132728 = 8;
      FUN_8009ced8();
      DAT_80132729 = 0;
      DAT_8013272c = 2;
    }
    if ((DAT_8013273a < 0x206) || (iVar1 = FUN_8002767c(DAT_8013272b), iVar1 == 0))
    goto LAB_8009de34;
    DAT_80132740 = 0;
    FUN_8009e8d4(0,1);
    DAT_80132729 = 1;
    DAT_8013272e = 7;
    goto LAB_8009ddb4;
  case 7:
    if ((DAT_8013273a != 100) || (DAT_80119e70 != '\0')) goto LAB_8009de34;
    DAT_800e90f8 = 1;
    DAT_800e110c = DAT_800e110c & 0xffffffef;
    FUN_8006c070(0);
    FUN_8009f320(3);
    DAT_8013272e = 8;
    goto LAB_8009ddb4;
  case 8:
    if ((DAT_800e10ec & 0x200) != 0) goto LAB_8009de34;
    FUN_8006c070(1);
    DAT_8013272e = 9;
    goto LAB_8009ddf4;
  case 9:
    if (DAT_8013273a != 1) goto LAB_8009de34;
    FUN_8006c070(0);
    FUN_8009f320(0x10);
    DAT_8013272e = 10;
LAB_8009ddb4:
    DAT_8013273a = 0;
    goto LAB_8009de34;
  case 10:
    if ((DAT_800e10ec & 0x200) != 0) goto LAB_8009de34;
    FUN_8006c070(1);
    DAT_8013272e = 0xb;
LAB_8009ddf4:
    DAT_8013273a = 0;
    goto LAB_8009de34;
  case 0xb:
    if (DAT_8013273a == 10) {
      DAT_8013272a = 3;
      DAT_8013273c = 4;
    }
  default:
    goto LAB_8009de34;
  }
  DAT_8013273a = 0;
LAB_8009de34:
  DAT_8013273a = DAT_8013273a + 1;
  return;
}
